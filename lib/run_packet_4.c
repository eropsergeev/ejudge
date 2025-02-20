/* -*- c -*- */

/* Copyright (C) 2005-2022 Alexander Chernov <cher@ejudge.ru> */

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

#include "ejudge/ej_types.h"
#include "ejudge/ej_limits.h"
#include "ejudge/ej_byteorder.h"
#include "ejudge/run_packet.h"
#include "ejudge/run_packet_priv.h"
#include "ejudge/pathutl.h"
#include "ejudge/errlog.h"
#include "ejudge/prepare.h"
#include "ejudge/runlog.h"

#include "ejudge/xalloc.h"
#include "ejudge/logger.h"
#include "ejudge/integral.h"

#include <stdlib.h>
#include <string.h>

#define FAIL_IF(c) if (c)do { errcode = __LINE__; goto failed; } while (0)

int
run_reply_packet_read(
        size_t in_size,
        const void *in_data,
        struct run_reply_packet **p_out_data)
{
  struct run_reply_packet *pout = 0;
  const struct run_reply_bin_packet *pin = (const struct run_reply_bin_packet*)in_data;
  int errcode = 0, version, flags;
  size_t packet_len;

  FAIL_IF(in_size != sizeof(*pin));
  packet_len = cvt_bin_to_host_32(pin->packet_len);
  FAIL_IF(packet_len != in_size);
  version = cvt_bin_to_host_32(pin->version);
  FAIL_IF(version != 1);

  pout = (typeof(pout)) xcalloc(1, sizeof(*pout));

  pout->judge_id = cvt_bin_to_host_32(pin->judge_id);
  FAIL_IF(pout->judge_id < 0 || pout->judge_id > EJ_MAX_JUDGE_ID);
  pout->contest_id = cvt_bin_to_host_32(pin->contest_id);
  FAIL_IF(pout->contest_id <= 0 || pout->contest_id > EJ_MAX_CONTEST_ID);
  pout->run_id = cvt_bin_to_host_32(pin->run_id);
  FAIL_IF(pout->run_id < 0 || pout->run_id > EJ_MAX_RUN_ID);
  pout->status = cvt_bin_to_host_32(pin->status);
  FAIL_IF(!run_is_normal_status(pout->status));
  pout->failed_test = cvt_bin_to_host_32(pin->failed_test);
  FAIL_IF(pout->failed_test < -1 || pout->failed_test > EJ_MAX_TEST_NUM);
  pout->tests_passed = cvt_bin_to_host_32(pin->tests_passed);
  FAIL_IF(pout->tests_passed < -1 || pout->tests_passed > EJ_MAX_TEST_NUM);
  pout->score = cvt_bin_to_host_32(pin->score);
  FAIL_IF(pout->score < -1 || pout->score > EJ_MAX_SCORE);

  pout->user_status = cvt_bin_to_host_32(pin->user_status);
  FAIL_IF(!run_is_normal_status(pout->user_status) && pout->user_status != -1);
  pout->user_tests_passed = cvt_bin_to_host_32(pin->user_tests_passed);
  FAIL_IF(pout->user_tests_passed < -1 || pout->user_tests_passed > EJ_MAX_TEST_NUM);
  pout->user_score = cvt_bin_to_host_32(pin->user_score);
  FAIL_IF(pout->user_score < -1 || pout->user_score > EJ_MAX_SCORE);

  flags = cvt_bin_to_host_32(pin->flags);
  if ((flags & FLAGS_NOTIFY)) pout->notify_flag = 1;
  if ((flags & FLAGS_MARKED)) pout->marked_flag = 1;
  if ((flags & FLAGS_HAS_USER_SCORE)) pout->has_user_score = 1;
  if ((flags & FLAGS_BSON)) pout->bson_flag = 1;

  pout->ts1 = cvt_bin_to_host_32(pin->ts1);
  pout->ts1_us = cvt_bin_to_host_32(pin->ts1_us);
  pout->ts2 = cvt_bin_to_host_32(pin->ts2);
  pout->ts2_us = cvt_bin_to_host_32(pin->ts2_us);
  pout->ts3 = cvt_bin_to_host_32(pin->ts3);
  pout->ts3_us = cvt_bin_to_host_32(pin->ts3_us);
  pout->ts4 = cvt_bin_to_host_32(pin->ts4);
  pout->ts4_us = cvt_bin_to_host_32(pin->ts4_us);
  pout->ts5 = cvt_bin_to_host_32(pin->ts5);
  pout->ts5_us = cvt_bin_to_host_32(pin->ts5_us);
  pout->ts6 = cvt_bin_to_host_32(pin->ts6);
  pout->ts6_us = cvt_bin_to_host_32(pin->ts6_us);
  pout->ts7 = cvt_bin_to_host_32(pin->ts7);
  pout->ts7_us = cvt_bin_to_host_32(pin->ts7_us);

  pout->uuid = pin->uuid;
  pout->judge_uuid = pin->judge_uuid;
  /*
  pout->uuid.v[0] = cvt_bin_to_host_32(pin->uuid.v[0]);
  pout->uuid.v[1] = cvt_bin_to_host_32(pin->uuid.v[1]);
  pout->uuid.v[2] = cvt_bin_to_host_32(pin->uuid.v[2]);
  pout->uuid.v[3] = cvt_bin_to_host_32(pin->uuid.v[3]);
  */

  *p_out_data = pout;
  return 0;

 failed:
  err("run_reply_packet_read: error %s, %d", "$Revision$", errcode);
  run_reply_packet_free(pout);
  return -1;
}
