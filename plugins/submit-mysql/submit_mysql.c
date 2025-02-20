/* -*- mode: c; c-basic-offset: 4 -*- */

/* Copyright (C) 2022 Alexander Chernov <cher@ejudge.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "ejudge/config.h"
#include "ejudge/common_plugin.h"
#include "ejudge/submit_plugin.h"
#include "../common-mysql/common_mysql.h"
#include "ejudge/contests.h"
#include "ejudge/errlog.h"
#include "ejudge/xalloc.h"
#include "ejudge/xml_utils.h"

struct submit_mysql_data
{
    struct submit_plugin_data b;

    int nref;

    // mysql access
    struct common_mysql_iface *mi;
    struct common_mysql_state *md;

    int is_db_checked;
};

static struct common_plugin_data *
init_func(void)
{
    struct submit_mysql_data *state = NULL;
    XCALLOC(state, 1);
    return &state->b.b;
}

static int
finish_func(struct common_plugin_data *data)
{
    return 0;
}

static int
prepare_func(
        struct common_plugin_data *data,
        const struct ejudge_cfg *config,
        struct xml_tree *tree)
{
    struct submit_mysql_data *smd = (struct submit_mysql_data *) data;
    const struct common_loaded_plugin *mplg;

    // load common_mysql plugin
    if (!(mplg = plugin_load_external(0, "common", "mysql", config))) {
        err("cannot load common_mysql plugin");
        return -1;
    }
    smd->mi = (struct common_mysql_iface*) mplg->iface;
    smd->md = (struct common_mysql_state*) mplg->data;

    return 0;
}

static const char create_query[] =
"CREATE TABLE `%ssubmits` (\n"
"    serial_id BIGINT NOT NULL PRIMARY KEY AUTO_INCREMENT,\n"
"    uuid CHAR(40) NOT NULL,\n"
"    contest_id INT NOT NULL,\n"
"    user_id INT UNSIGNED NOT NULL,\n"
"    prob_id INT UNSIGNED NOT NULL DEFAULT 0,\n"
"    prob_uuid VARCHAR(40) DEFAULT NULL,\n"
"    variant INT DEFAULT NULL,\n"
"    lang_id INT UNSIGNED NOT NULL DEFAULT 0,\n"
"    status INT NOT NULL DEFAULT 99,\n"
"    ssl_flag TINYINT NOT NULL DEFAULT 0,\n"
"    ip_version TINYINT NOT NULL DEFAULT 4,\n"
"    ip VARCHAR(64) DEFAULT NULL,\n"
"    locale_id INT NOT NULL DEFAULT 0,\n "
"    eoln_type TINYINT NOT NULL DEFAULT 0,\n"
"    judge_uuid VARCHAR(40) DEFAULT NULL,\n"
"    create_time DATETIME(6) NOT NULL,\n"
"    last_status_change_time DATETIME(6) DEFAULT NULL,\n"
"    source_id BIGINT DEFAULT NULL,\n"
"    input_id BIGINT DEFAULT NULL,\n"
"    protocol_id BIGINT DEFAULT NULL,\n"
"    source_size BIGINT NOT NULL DEFAULT 0,\n"
"    input_size BIGINT NOT NULL DEFAULT 0,\n"
"    UNIQUE KEY s_uuid_idx(uuid),\n"
"    KEY s_contest_id_idx(contest_id),\n"
"    KEY s_user_id_idx(user_id),\n"
"    KEY s_uc_ids_idx(user_id,contest_id),\n"
"    KEY s_judge_idx(judge_uuid),\n"
"    FOREIGN KEY s_user_id_fk(user_id) REFERENCES %slogins(user_id),\n"
"    FOREIGN KEY s_source_id_fk(source_id) REFERENCES `%sstorage`(serial_id),\n"
"    FOREIGN KEY s_input_id_fk(input_id) REFERENCES `%sstorage`(serial_id),\n"
"    FOREIGN KEY s_protocol_id_fk(protocol_id) REFERENCES `%sstorage`(serial_id)\n"
") ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;\n";

static int
create_database(
        struct submit_mysql_data *smd)
{
    struct common_mysql_iface *mi = smd->mi;
    struct common_mysql_state *md = smd->md;

    if (mi->simple_fquery(md, create_query,
                          md->table_prefix,
                          md->table_prefix,
                          md->table_prefix,
                          md->table_prefix,
                          md->table_prefix) < 0)
        db_error_fail(md);

    if (mi->simple_fquery(md, "INSERT INTO %sconfig VALUES ('submit_version', '%d') ;", md->table_prefix, 1) < 0)
        db_error_fail(md);

    smd->is_db_checked = 1;
    return 0;

fail:
    return -1;
}

static int
check_database(
        struct submit_mysql_data *smd)
{
    int submit_version = 0;
    struct common_mysql_iface *mi = smd->mi;
    struct common_mysql_state *md = smd->md;

    if (mi->connect(md) < 0)
        goto fail;

    if (mi->fquery(md, 1, "SELECT config_val FROM %sconfig WHERE config_key = 'submit_version' ;", md->table_prefix) < 0) {
        err("probably the database is not created, please, create it");
        goto fail;
    }
    if (md->row_count > 1) {
        err("submit_version key is not unique");
        goto fail;
    }
    if (!md->row_count) return create_database(smd);
    if (mi->next_row(md) < 0) db_error_fail(md);
    if (!md->row[0] || mi->parse_int(md, md->row[0], &submit_version) < 0)
        db_error_inv_value_fail(md, "config_val");
    mi->free_res(md);
    if (submit_version < 1) {
        err("submit_version == %d is not supported", submit_version);
        goto fail;
    }

    while (submit_version >= 0) {
        switch (submit_version) {
        default:
            submit_version = -1;
            break;
        }
        if (submit_version >= 0) {
            ++submit_version;
            if (mi->simple_fquery(md, "UPDATE %sconfig SET config_val = '%d' WHERE config_key = 'submit_version' ;", md->table_prefix, submit_version) < 0)
                return -1;
        }
    }

    smd->is_db_checked = 1;
    return 0;

fail:
    return -1;
}

struct submit_cnts_mysql_data
{
    struct submit_cnts_plugin_data b;
    struct submit_mysql_data *smd;
    int contest_id;
};

extern struct submit_plugin_iface plugin_submit_mysql;

static struct submit_cnts_plugin_data *
open_func(
        struct common_plugin_data *data,
        const struct ejudge_cfg *config,
        const struct contest_desc *cnts,
        const struct serve_state *state,
        int flags)
{
    struct submit_mysql_data *smd = (struct submit_mysql_data *) data;

    if (!smd->is_db_checked) {
        if (check_database(smd) < 0) {
            return NULL;
        }
        smd->is_db_checked = 1;
    }

    struct submit_cnts_mysql_data *scmd = NULL;
    XCALLOC(scmd, 1);
    scmd->b.vt = &plugin_submit_mysql;
    scmd->smd = smd;
    scmd->contest_id = cnts->id;
    ++smd->nref;
    
    return &scmd->b;
}

static struct submit_cnts_plugin_data *
close_func(
        struct submit_cnts_plugin_data *data)
{
    struct submit_cnts_mysql_data *scmd = (struct submit_cnts_mysql_data *) data;
    if (scmd) {
        if (scmd->smd && scmd->smd->nref > 0) {
            --scmd->smd->nref;
        }
        xfree(scmd);
    }
    return NULL;
}

struct submit_entry_internal
{
    int64_t serial_id;
    ej_uuid_t uuid;
    int contest_id;
    int user_id;
    int prob_id;
    ej_uuid_t prob_uuid;
    int variant;
    int lang_id;
    int status;
    int ssl_flag;
    int ip_version;
    ej_ip_t ip;
    int locale_id;
    int eoln_type;
    ej_uuid_t judge_uuid;
    struct timeval create_time;
    struct timeval last_status_change_time;
    int64_t source_id;
    int64_t input_id;
    int64_t protocol_id;
    int64_t source_size;
    int64_t input_size;
};

enum { SUBMIT_ROW_WIDTH = 22 };
#define SUBMIT_OFFSET(f) XOFFSET(struct submit_entry_internal, f)
[[gnu::unused]]
static const struct common_mysql_parse_spec submit_spec[SUBMIT_ROW_WIDTH] =
{
    { 0, 'l', "serial_id", SUBMIT_OFFSET(serial_id), 0 },
    { 1, 'g', "uuid", SUBMIT_OFFSET(uuid), 0 },
    { 0, 'd', "contest_id", SUBMIT_OFFSET(contest_id), 0 },
    { 0, 'd', "user_id", SUBMIT_OFFSET(user_id), 0 },
    { 0, 'd', "prob_id", SUBMIT_OFFSET(prob_id), 0 },
    { 1, 'g', "prob_uuid", SUBMIT_OFFSET(prob_uuid), 0 },
    { 1, 'd', "variant", SUBMIT_OFFSET(variant), 0 },
    { 0, 'd', "lang_id", SUBMIT_OFFSET(lang_id), 0 },
    { 0, 'd', "status", SUBMIT_OFFSET(status), 0 },
    { 0, 'd', "ssl_flag", SUBMIT_OFFSET(ssl_flag), 0 },
    { 0, 'd', "ip_version", SUBMIT_OFFSET(ip_version), 0 },
    { 1, 'I', "ip", SUBMIT_OFFSET(ip), 0 },
    { 0, 'd', "locale_id", SUBMIT_OFFSET(locale_id), 0 },
    { 0, 'd', "eoln_type", SUBMIT_OFFSET(eoln_type), 0 },
    { 1, 'g', "judge_uuid", SUBMIT_OFFSET(judge_uuid), 0 },
    { 1, 'T', "create_time", SUBMIT_OFFSET(create_time), 0 },
    { 1, 'T', "last_status_change_time", SUBMIT_OFFSET(last_status_change_time), 0 },
    { 1, 'l', "source_id", SUBMIT_OFFSET(source_id), 0 },
    { 1, 'l', "input_id", SUBMIT_OFFSET(input_id), 0 },
    { 1, 'l', "protocol_id", SUBMIT_OFFSET(protocol_id), 0 },
    { 1, 'l', "source_size", SUBMIT_OFFSET(source_size), 0 },
    { 1, 'l', "input_size", SUBMIT_OFFSET(input_size), 0 },
};

static int
insert_func(
        struct submit_cnts_plugin_data *data,
        struct submit_entry *pse)
{
    struct submit_cnts_mysql_data *scmd = (struct submit_cnts_mysql_data *) data;
    struct submit_mysql_data *smd = scmd->smd;
    struct common_mysql_iface *mi = smd->mi;
    struct common_mysql_state *md = smd->md;
    char *cmd_s = NULL;
    size_t cmd_z = 0;
    FILE *cmd_f = NULL;
    unsigned char uuid_buf[64];

    if (!ej_uuid_is_nonempty(pse->uuid)) {
        ej_uuid_generate(&pse->uuid);
    }
    pse->contest_id = scmd->contest_id;

    cmd_f = open_memstream(&cmd_s, &cmd_z);
    fprintf(cmd_f, "INSERT INTO %ssubmits VALUES(DEFAULT",
            md->table_prefix);
    fprintf(cmd_f, ",'%s'", ej_uuid_unparse_r(uuid_buf, sizeof(uuid_buf),
                                              &pse->uuid, NULL));
    fprintf(cmd_f, ",%d", pse->contest_id);
    fprintf(cmd_f, ",%d", pse->user_id);
    fprintf(cmd_f, ",%d", pse->prob_id);
    if (ej_uuid_is_nonempty(pse->prob_uuid)) {
        fprintf(cmd_f, ",'%s'", ej_uuid_unparse_r(uuid_buf, sizeof(uuid_buf),
                                                  &pse->prob_uuid, NULL));
    } else {
        fprintf(cmd_f, ",NULL");
    }
    if (pse->variant > 0) {
        fprintf(cmd_f, ",%d", pse->variant);
    } else {
        fprintf(cmd_f, ",NULL");
    }
    fprintf(cmd_f, ",%d", pse->lang_id);
    fprintf(cmd_f, ",%d", pse->status);
    fprintf(cmd_f, ",%d", pse->ssl_flag);
    if (pse->ip.ipv6_flag) {
        fprintf(cmd_f, ",6");
    } else {
        fprintf(cmd_f, ",4");
    }
    fprintf(cmd_f, ",'%s'", xml_unparse_ipv6(&pse->ip));
    fprintf(cmd_f, ",%d", pse->locale_id);
    fprintf(cmd_f, ",%d", pse->eoln_type);
    if (ej_uuid_is_nonempty(pse->judge_uuid)) {
        fprintf(cmd_f, ",'%s'", ej_uuid_unparse_r(uuid_buf, sizeof(uuid_buf),
                                                  &pse->judge_uuid, NULL));
    } else {
        fprintf(cmd_f, ",NULL");
    }
    fprintf(cmd_f, ",NOW(6)");
    fprintf(cmd_f, ",NOW(6)");
    if (pse->source_id > 0) {
        fprintf(cmd_f, ",%lld", (long long) pse->source_id);
    } else {
        fprintf(cmd_f, ",NULL");
    }
    if (pse->input_id > 0) {
        fprintf(cmd_f, ",%lld", (long long) pse->input_id);
    } else {
        fprintf(cmd_f, ",NULL");
    }
    if (pse->protocol_id > 0) {
        fprintf(cmd_f, ",%lld", (long long) pse->protocol_id);
    } else {
        fprintf(cmd_f, ",NULL");
    }
    fprintf(cmd_f, ",%lld", (long long) pse->source_size);
    fprintf(cmd_f, ",%lld", (long long) pse->input_size);
    fprintf(cmd_f, ")");
    fclose(cmd_f); cmd_f = NULL;

    if (mi->simple_query(md, cmd_s, cmd_z) < 0) goto fail;
    free(cmd_s); cmd_s = NULL; cmd_z = 0;

    if (mi->fquery(md, 1, "SELECT LAST_INSERT_ID();") < 0) {
        goto fail;
    }
    if (md->row_count <= 0) {
        goto fail;
    }
    if (mi->next_row(md) < 0) {
        goto fail;
    }
    long long serial_id = 0;
    if (mi->parse_int64(md, 0, &serial_id) < 0) {
        goto fail;
    }
    pse->serial_id = serial_id;
    mi->free_res(md);

    return 0;
fail:
    if (cmd_f) fclose(cmd_f);
    free(cmd_s);
    return -1;
}


static int
change_status_func(
        struct submit_cnts_plugin_data *data,
        int64_t submit_id,
        unsigned mask,
        int status,
        int64_t protocol_id,
        ej_uuid_t *p_judge_uuid)
{
    struct submit_cnts_mysql_data *scmd = (struct submit_cnts_mysql_data *) data;
    struct submit_mysql_data *smd = scmd->smd;
    struct common_mysql_iface *mi = smd->mi;
    struct common_mysql_state *md = smd->md;
    char *cmd_s = NULL;
    size_t cmd_z = 0;
    FILE *cmd_f = NULL;
    unsigned char uuid_buf[64];

    cmd_f = open_memstream(&cmd_s, &cmd_z);
    fprintf(cmd_f, "UPDATE %ssubmits SET last_status_change_time = NOW(6)",
            md->table_prefix);
    if ((mask & SUBMIT_FIELD_STATUS)) {
        fprintf(cmd_f, ", status = %d", status);
    }
    if ((mask & SUBMIT_FIELD_PROTOCOL_ID)) {
        if (protocol_id > 0) {
            fprintf(cmd_f, ", protocol_id = %lld", (long long) protocol_id);
        } else {
            fprintf(cmd_f, ", protocol_id = NULL");
        }
    }
    if ((mask & SUBMIT_FIELD_JUDGE_UUID)) {
        if (p_judge_uuid && ej_uuid_is_nonempty(*p_judge_uuid)) {
            fprintf(cmd_f, ", '%s'",
                    ej_uuid_unparse_r(uuid_buf, sizeof(uuid_buf),
                                      p_judge_uuid, NULL));
        } else {
            fprintf(cmd_f, ", judge_uuid = NULL");
        }
    }
    fprintf(cmd_f, " WHERE serial_id = %lld;", (long long) submit_id);
    fclose(cmd_f); cmd_f = NULL;

    if (mi->simple_query(md, cmd_s, cmd_z) < 0) goto fail;
    free(cmd_s); cmd_s = NULL; cmd_z = 0;
    return 0;

fail:
    if (cmd_f) fclose(cmd_f);
    free(cmd_s);
    return -1;
}

struct submit_plugin_iface plugin_submit_mysql =
{
    {
        {
            sizeof (struct submit_plugin_iface),
            EJUDGE_PLUGIN_IFACE_VERSION,
            "submit",
            "mysql",
        },
        COMMON_PLUGIN_IFACE_VERSION,
        init_func,
        finish_func,
        prepare_func,
    },
    SUBMIT_PLUGIN_IFACE_VERSION,
    open_func,
    close_func,
    insert_func,
    change_status_func,
};
