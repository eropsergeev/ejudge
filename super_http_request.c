/* -*- mode: c -*- */

/* Copyright (C) 2014-2015 Alexander Chernov <cher@ejudge.ru> */

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

#include "ejudge/super_proto.h"

const unsigned char super_proto_is_http_request[] =
{
  [SSERV_CMD_PASS_FD] = 0,
  [SSERV_CMD_STOP] = 0,
  [SSERV_CMD_RESTART] = 0,
  [SSERV_CMD_OPEN_CONTEST] = 0,
  [SSERV_CMD_CLOSE_CONTEST] = 0,
  [SSERV_CMD_INVISIBLE_CONTEST] = 0,
  [SSERV_CMD_VISIBLE_CONTEST] = 0,
  [SSERV_CMD_SHOW_HIDDEN] = 0,
  [SSERV_CMD_HIDE_HIDDEN] = 0,
  [SSERV_CMD_SHOW_CLOSED] = 0,
  [SSERV_CMD_HIDE_CLOSED] = 0,
  [SSERV_CMD_SHOW_UNMNG] = 0,
  [SSERV_CMD_HIDE_UNMNG] = 0,
  [SSERV_CMD_RUN_LOG_TRUNC] = 0,
  [SSERV_CMD_RUN_LOG_DEV_NULL] = 0,
  [SSERV_CMD_RUN_LOG_FILE] = 0,
  [SSERV_CMD_RUN_MNG_TERM] = 0,
  [SSERV_CMD_CONTEST_RESTART] = 0,
  [SSERV_CMD_CLEAR_MESSAGES] = 0,
  [SSERV_CMD_RUN_MNG_RESET_ERROR] = 0,
  [SSERV_CMD_CNTS_FORGET] = 0,
  [SSERV_CMD_CNTS_DEFAULT_ACCESS] = 0,
  [SSERV_CMD_CNTS_ADD_RULE] = 0,
  [SSERV_CMD_CNTS_CHANGE_RULE] = 0,
  [SSERV_CMD_CNTS_DELETE_RULE] = 0,
  [SSERV_CMD_CNTS_UP_RULE] = 0,
  [SSERV_CMD_CNTS_DOWN_RULE] = 0,
  [SSERV_CMD_CNTS_COPY_ACCESS] = 0,
  [SSERV_CMD_CNTS_DELETE_PERMISSION] = 0,
  [SSERV_CMD_CNTS_ADD_PERMISSION] = 0,
  [SSERV_CMD_CNTS_SAVE_PERMISSIONS] = 0,
  [SSERV_CMD_CNTS_SET_PREDEF_PERMISSIONS] = 0, /* implemented in serve-control */
  [SSERV_CMD_CNTS_SAVE_FORM_FIELDS] = 0,
  [SSERV_CMD_CNTS_SAVE_CONTESTANT_FIELDS] = 0, /* NOTE: the following 5 commands must */
  [SSERV_CMD_CNTS_SAVE_RESERVE_FIELDS] = 0,    /* be sequental */
  [SSERV_CMD_CNTS_SAVE_COACH_FIELDS] = 0,
  [SSERV_CMD_CNTS_SAVE_ADVISOR_FIELDS] = 0,
  [SSERV_CMD_CNTS_SAVE_GUEST_FIELDS] = 0,
  [SSERV_CMD_LANG_SHOW_DETAILS] = 0,
  [SSERV_CMD_LANG_HIDE_DETAILS] = 0,
  [SSERV_CMD_LANG_DEACTIVATE] = 0,
  [SSERV_CMD_LANG_ACTIVATE] = 0,
  [SSERV_CMD_PROB_ADD_ABSTRACT] = 0,
  [SSERV_CMD_PROB_ADD] = 0,
  [SSERV_CMD_PROB_SHOW_DETAILS] = 0,
  [SSERV_CMD_PROB_HIDE_DETAILS] = 0,
  [SSERV_CMD_PROB_SHOW_ADVANCED] = 0,
  [SSERV_CMD_PROB_HIDE_ADVANCED] = 0,
  [SSERV_CMD_GLOB_CHANGE_TOKENS] = 0,
  [SSERV_CMD_GLOB_CLEAR_TOKENS] = 0,
  [SSERV_CMD_GLOB_CHANGE_STAND_COLLATE_NAME] = 0,
  [SSERV_CMD_GLOB_CHANGE_MEMOIZE_USER_RESULTS] = 0,
  [SSERV_CMD_GLOB_CHANGE_ENABLE_CONTINUE] = 0,
  [SSERV_CMD_GLOB_CHANGE_TEAM_DOWNLOAD_TIME] = 0,
  [SSERV_CMD_GLOB_DISABLE_TEAM_DOWNLOAD_TIME] = 0,
  [SSERV_CMD_GLOB_CHANGE_COMPILE_MAX_VM_SIZE] = 0,
  [SSERV_CMD_GLOB_CHANGE_COMPILE_MAX_STACK_SIZE] = 0,
  [SSERV_CMD_GLOB_CHANGE_COMPILE_MAX_FILE_SIZE] = 0,
  [SSERV_CMD_LANG_CHANGE_DISABLED] = 0,
  [SSERV_CMD_LANG_CHANGE_INSECURE] = 0,
  [SSERV_CMD_LANG_CHANGE_LONG_NAME] = 0,
  [SSERV_CMD_LANG_CLEAR_LONG_NAME] = 0,
  [SSERV_CMD_LANG_CHANGE_EXTID] = 0,
  [SSERV_CMD_LANG_CLEAR_EXTID] = 0,
  [SSERV_CMD_LANG_CHANGE_DISABLE_SECURITY] = 0,
  [SSERV_CMD_LANG_CHANGE_DISABLE_AUTO_TESTING] = 0,
  [SSERV_CMD_LANG_CHANGE_DISABLE_TESTING] = 0,
  [SSERV_CMD_LANG_CHANGE_BINARY] = 0,
  [SSERV_CMD_LANG_CHANGE_IS_DOS] = 0,
  [SSERV_CMD_LANG_CHANGE_MAX_VM_SIZE] = 0,
  [SSERV_CMD_LANG_CHANGE_MAX_STACK_SIZE] = 0,
  [SSERV_CMD_LANG_CHANGE_MAX_FILE_SIZE] = 0,
  [SSERV_CMD_LANG_CHANGE_CONTENT_TYPE] = 0,
  [SSERV_CMD_LANG_CLEAR_CONTENT_TYPE] = 0,
  [SSERV_CMD_LANG_CHANGE_OPTS] = 0,
  [SSERV_CMD_LANG_CLEAR_OPTS] = 0,
  [SSERV_CMD_LANG_CHANGE_LIBS] = 0,
  [SSERV_CMD_LANG_CLEAR_LIBS] = 0,
  [SSERV_CMD_LANG_CHANGE_STYLE_CHECKER_CMD] = 0,
  [SSERV_CMD_LANG_CLEAR_STYLE_CHECKER_CMD] = 0,
  [SSERV_CMD_LANG_CHANGE_STYLE_CHECKER_ENV] = 0,
  [SSERV_CMD_LANG_CLEAR_STYLE_CHECKER_ENV] = 0,
  [SSERV_CMD_PROB_DELETE] = 0,
  [SSERV_CMD_PROB_CHANGE_SHORT_NAME] = 0,
  [SSERV_CMD_PROB_CLEAR_SHORT_NAME] = 0,
  [SSERV_CMD_PROB_CHANGE_LONG_NAME] = 0,
  [SSERV_CMD_PROB_CLEAR_LONG_NAME] = 0,
  [SSERV_CMD_PROB_CHANGE_STAND_NAME] = 0,
  [SSERV_CMD_PROB_CLEAR_STAND_NAME] = 0,
  [SSERV_CMD_PROB_CHANGE_STAND_COLUMN] = 0,
  [SSERV_CMD_PROB_CLEAR_STAND_COLUMN] = 0,
  [SSERV_CMD_PROB_CHANGE_INTERNAL_NAME] = 0,
  [SSERV_CMD_PROB_CLEAR_INTERNAL_NAME] = 0,
  [SSERV_CMD_PROB_CHANGE_SUPER] = 0,
  [SSERV_CMD_PROB_CHANGE_TYPE] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORING_CHECKER] = 0,
  [SSERV_CMD_PROB_CHANGE_INTERACTIVE_VALUER] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_PE] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_WTL] = 0,
  [SSERV_CMD_PROB_CHANGE_MANUAL_CHECKING] = 0,
  [SSERV_CMD_PROB_CHANGE_EXAMINATOR_NUM] = 0,
  [SSERV_CMD_PROB_CHANGE_CHECK_PRESENTATION] = 0,
  [SSERV_CMD_PROB_CHANGE_USE_STDIN] = 0,
  [SSERV_CMD_PROB_CHANGE_USE_STDOUT] = 0,
  [SSERV_CMD_PROB_CHANGE_COMBINED_STDIN] = 0,
  [SSERV_CMD_PROB_CHANGE_COMBINED_STDOUT] = 0,
  [SSERV_CMD_PROB_CHANGE_BINARY_INPUT] = 0,
  [SSERV_CMD_PROB_CHANGE_BINARY] = 0,
  [SSERV_CMD_PROB_CHANGE_IGNORE_EXIT_CODE] = 0,
  [SSERV_CMD_PROB_CHANGE_OLYMPIAD_MODE] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORE_LATEST] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORE_LATEST_OR_UNMARKED] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORE_LATEST_MARKED] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORE_TOKENIZED] = 0,
  [SSERV_CMD_PROB_CHANGE_TIME_LIMIT] = 0,
  [SSERV_CMD_PROB_CHANGE_TIME_LIMIT_MILLIS] = 0,
  [SSERV_CMD_PROB_CHANGE_REAL_TIME_LIMIT] = 0,
  [SSERV_CMD_PROB_CHANGE_USE_AC_NOT_OK] = 0,
  [SSERV_CMD_PROB_CHANGE_IGNORE_PREV_AC] = 0,
  [SSERV_CMD_PROB_CHANGE_TEAM_ENABLE_REP_VIEW] = 0,
  [SSERV_CMD_PROB_CHANGE_TEAM_ENABLE_CE_VIEW] = 0,
  [SSERV_CMD_PROB_CHANGE_TEAM_SHOW_JUDGE_REPORT] = 0,
  [SSERV_CMD_PROB_CHANGE_SHOW_CHECKER_COMMENT] = 0,
  [SSERV_CMD_PROB_CHANGE_IGNORE_COMPILE_ERRORS] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_USER_SUBMIT] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_TAB] = 0,
  [SSERV_CMD_PROB_CHANGE_UNRESTRICTED_STATEMENT] = 0,
  [SSERV_CMD_PROB_CHANGE_HIDE_FILE_NAMES] = 0,
  [SSERV_CMD_PROB_CHANGE_HIDE_REAL_TIME_LIMIT] = 0,
  [SSERV_CMD_PROB_CHANGE_ENABLE_TOKENS] = 0,
  [SSERV_CMD_PROB_CHANGE_TOKENS_FOR_USER_AC] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_SUBMIT_AFTER_OK] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_SECURITY] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_TESTING] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_AUTO_TESTING] = 0,
  [SSERV_CMD_PROB_CHANGE_ENABLE_COMPILATION] = 0,
  [SSERV_CMD_PROB_CHANGE_FULL_SCORE] = 0,
  [SSERV_CMD_PROB_CHANGE_FULL_USER_SCORE] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_SCORE] = 0,
  [SSERV_CMD_PROB_CHANGE_RUN_PENALTY] = 0,
  [SSERV_CMD_PROB_CHANGE_ACM_RUN_PENALTY] = 0,
  [SSERV_CMD_PROB_CHANGE_DISQUALIFIED_PENALTY] = 0,
  [SSERV_CMD_PROB_CHANGE_VARIABLE_FULL_SCORE] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_SCORE_LIST] = 0,
  [SSERV_CMD_PROB_CLEAR_TEST_SCORE_LIST] = 0,
  [SSERV_CMD_PROB_CHANGE_TOKENS] = 0,
  [SSERV_CMD_PROB_CLEAR_TOKENS] = 0,
  [SSERV_CMD_PROB_CHANGE_UMASK] = 0,
  [SSERV_CMD_PROB_CLEAR_UMASK] = 0,
  [SSERV_CMD_PROB_CHANGE_OK_STATUS] = 0,
  [SSERV_CMD_PROB_CLEAR_OK_STATUS] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORE_TESTS] = 0,
  [SSERV_CMD_PROB_CLEAR_SCORE_TESTS] = 0,
  [SSERV_CMD_PROB_CHANGE_TESTS_TO_ACCEPT] = 0,
  [SSERV_CMD_PROB_CHANGE_ACCEPT_PARTIAL] = 0,
  [SSERV_CMD_PROB_CHANGE_MIN_TESTS_TO_ACCEPT] = 0,
  [SSERV_CMD_PROB_CHANGE_HIDDEN] = 0,
  [SSERV_CMD_PROB_CHANGE_STAND_HIDE_TIME] = 0,
  [SSERV_CMD_PROB_CHANGE_ADVANCE_TO_NEXT] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_CTRL_CHARS] = 0,
  [SSERV_CMD_PROB_CHANGE_VALUER_SETS_MARKED] = 0,
  [SSERV_CMD_PROB_CHANGE_IGNORE_UNMARKED] = 0,  
  [SSERV_CMD_PROB_CHANGE_DISABLE_STDERR] = 0,
  [SSERV_CMD_PROB_CHANGE_ENABLE_PROCESS_GROUP] = 0,
  [SSERV_CMD_PROB_CHANGE_HIDE_VARIANT] = 0,
  [SSERV_CMD_PROB_CHANGE_AUTOASSIGN_VARIANTS] = 0,
  [SSERV_CMD_PROB_CHANGE_ENABLE_TEXT_FORM] = 0,
  [SSERV_CMD_PROB_CHANGE_STAND_IGNORE_SCORE] = 0,
  [SSERV_CMD_PROB_CHANGE_STAND_LAST_COLUMN] = 0,
  [SSERV_CMD_PROB_CHANGE_CHECKER_REAL_TIME_LIMIT] = 0,
  [SSERV_CMD_PROB_CHANGE_INTERACTOR_TIME_LIMIT] = 0,
  [SSERV_CMD_PROB_CHANGE_MAX_VM_SIZE] = 0,
  [SSERV_CMD_PROB_CHANGE_MAX_STACK_SIZE] = 0,
  [SSERV_CMD_PROB_CHANGE_MAX_CORE_SIZE] = 0,
  [SSERV_CMD_PROB_CHANGE_MAX_FILE_SIZE] = 0,
  [SSERV_CMD_PROB_CHANGE_MAX_OPEN_FILE_COUNT] = 0,
  [SSERV_CMD_PROB_CHANGE_MAX_PROCESS_COUNT] = 0,
  [SSERV_CMD_PROB_CHANGE_MAX_USER_RUN_COUNT] = 0,
  [SSERV_CMD_PROB_CHANGE_INPUT_FILE] = 0,
  [SSERV_CMD_PROB_CLEAR_INPUT_FILE] = 0,
  [SSERV_CMD_PROB_CHANGE_OUTPUT_FILE] = 0,
  [SSERV_CMD_PROB_CLEAR_OUTPUT_FILE] = 0,
  [SSERV_CMD_PROB_CHANGE_USE_CORR] = 0,
  [SSERV_CMD_PROB_CHANGE_USE_INFO] = 0,
  [SSERV_CMD_PROB_CHANGE_USE_TGZ] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_DIR] = 0,
  [SSERV_CMD_PROB_CLEAR_TEST_DIR] = 0,
  [SSERV_CMD_PROB_CHANGE_CORR_DIR] = 0,
  [SSERV_CMD_PROB_CLEAR_CORR_DIR] = 0,
  [SSERV_CMD_PROB_CHANGE_INFO_DIR] = 0,
  [SSERV_CMD_PROB_CLEAR_INFO_DIR] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_SFX] = 0,
  [SSERV_CMD_PROB_CLEAR_TEST_SFX] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_PAT] = 0,
  [SSERV_CMD_PROB_CLEAR_TEST_PAT] = 0,
  [SSERV_CMD_PROB_CHANGE_CORR_SFX] = 0,
  [SSERV_CMD_PROB_CLEAR_CORR_SFX] = 0,
  [SSERV_CMD_PROB_CHANGE_CORR_PAT] = 0,
  [SSERV_CMD_PROB_CLEAR_CORR_PAT] = 0,
  [SSERV_CMD_PROB_CHANGE_INFO_SFX] = 0,
  [SSERV_CMD_PROB_CLEAR_INFO_SFX] = 0,
  [SSERV_CMD_PROB_CHANGE_INFO_PAT] = 0,
  [SSERV_CMD_PROB_CLEAR_INFO_PAT] = 0,
  [SSERV_CMD_PROB_CHANGE_TGZ_SFX] = 0,
  [SSERV_CMD_PROB_CLEAR_TGZ_SFX] = 0,
  [SSERV_CMD_PROB_CHANGE_TGZ_PAT] = 0,
  [SSERV_CMD_PROB_CLEAR_TGZ_PAT] = 0,
  [SSERV_CMD_PROB_CHANGE_TGZDIR_SFX] = 0,
  [SSERV_CMD_PROB_CLEAR_TGZDIR_SFX] = 0,
  [SSERV_CMD_PROB_CHANGE_TGZDIR_PAT] = 0,
  [SSERV_CMD_PROB_CLEAR_TGZDIR_PAT] = 0,
  [SSERV_CMD_PROB_CHANGE_STANDARD_CHECKER] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORE_BONUS] = 0,
  [SSERV_CMD_PROB_CLEAR_SCORE_BONUS] = 0,
  [SSERV_CMD_PROB_CHANGE_OPEN_TESTS] = 0,
  [SSERV_CMD_PROB_CLEAR_OPEN_TESTS] = 0,
  [SSERV_CMD_PROB_CHANGE_FINAL_OPEN_TESTS] = 0,
  [SSERV_CMD_PROB_CLEAR_FINAL_OPEN_TESTS] = 0,
  [SSERV_CMD_PROB_CHANGE_TOKEN_OPEN_TESTS] = 0,
  [SSERV_CMD_PROB_CLEAR_TOKEN_OPEN_TESTS] = 0,
  [SSERV_CMD_PROB_CHANGE_LANG_COMPILER_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_LANG_COMPILER_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_CHECK_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_CHECK_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_CHECKER_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_CHECKER_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_VALUER_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_VALUER_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_VALUER_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_VALUER_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_INTERACTOR_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_INTERACTOR_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_INTERACTOR_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_INTERACTOR_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_STYLE_CHECKER_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_STYLE_CHECKER_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_STYLE_CHECKER_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_STYLE_CHECKER_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_CHECKER_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_TEST_CHECKER_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_CHECKER_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_TEST_CHECKER_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_INIT_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_INIT_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_START_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_START_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_INIT_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_INIT_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_START_ENV] = 0,
  [SSERV_CMD_PROB_CLEAR_START_ENV] = 0,
  [SSERV_CMD_PROB_CHANGE_SOLUTION_SRC] = 0,
  [SSERV_CMD_PROB_CLEAR_SOLUTION_SRC] = 0,
  [SSERV_CMD_PROB_CHANGE_SOLUTION_CMD] = 0,
  [SSERV_CMD_PROB_CLEAR_SOLUTION_CMD] = 0,
  [SSERV_CMD_PROB_CHANGE_LANG_TIME_ADJ] = 0,
  [SSERV_CMD_PROB_CLEAR_LANG_TIME_ADJ] = 0,
  [SSERV_CMD_PROB_CHANGE_LANG_TIME_ADJ_MILLIS] = 0,
  [SSERV_CMD_PROB_CLEAR_LANG_TIME_ADJ_MILLIS] = 0,
  [SSERV_CMD_PROB_CHANGE_LANG_MAX_VM_SIZE] = 0,
  [SSERV_CMD_PROB_CLEAR_LANG_MAX_VM_SIZE] = 0,
  [SSERV_CMD_PROB_CHANGE_LANG_MAX_STACK_SIZE] = 0,
  [SSERV_CMD_PROB_CLEAR_LANG_MAX_STACK_SIZE] = 0,
  [SSERV_CMD_PROB_CHANGE_DISABLE_LANGUAGE] = 0,
  [SSERV_CMD_PROB_CLEAR_DISABLE_LANGUAGE] = 0,
  [SSERV_CMD_PROB_CHANGE_ENABLE_LANGUAGE] = 0,
  [SSERV_CMD_PROB_CLEAR_ENABLE_LANGUAGE] = 0,
  [SSERV_CMD_PROB_CHANGE_REQUIRE] = 0,
  [SSERV_CMD_PROB_CLEAR_REQUIRE] = 0,
  [SSERV_CMD_PROB_CHANGE_PROVIDE_OK] = 0,
  [SSERV_CMD_PROB_CLEAR_PROVIDE_OK] = 0,
  [SSERV_CMD_PROB_CHANGE_TEST_SETS] = 0,
  [SSERV_CMD_PROB_CLEAR_TEST_SETS] = 0,
  [SSERV_CMD_PROB_CHANGE_SCORE_VIEW] = 0,
  [SSERV_CMD_PROB_CLEAR_SCORE_VIEW] = 0,
  [SSERV_CMD_PROB_CHANGE_START_DATE] = 0,
  [SSERV_CMD_PROB_CLEAR_START_DATE] = 0,
  [SSERV_CMD_PROB_CHANGE_DEADLINE] = 0,
  [SSERV_CMD_PROB_CLEAR_DEADLINE] = 0,
  [SSERV_CMD_PROB_CHANGE_VARIANT_NUM] = 0,
  [SSERV_CMD_PROB_CHANGE_VARIANTS] = 0,
  [SSERV_CMD_PROB_DELETE_VARIANTS] = 0,
  [SSERV_CMD_PROB_CHANGE_XML_FILE] = 0,
  [SSERV_CMD_PROB_CLEAR_XML_FILE] = 0,
  [SSERV_CMD_PROB_CHANGE_ALTERNATIVES_FILE] = 0,
  [SSERV_CMD_PROB_CLEAR_ALTERNATIVES_FILE] = 0,
  [SSERV_CMD_PROB_CHANGE_PLUGIN_FILE] = 0,
  [SSERV_CMD_PROB_CLEAR_PLUGIN_FILE] = 0,
  [SSERV_CMD_PROB_CHANGE_STAND_ATTR] = 0,
  [SSERV_CMD_PROB_CLEAR_STAND_ATTR] = 0,
  [SSERV_CMD_PROB_CHANGE_SOURCE_HEADER] = 0,
  [SSERV_CMD_PROB_CLEAR_SOURCE_HEADER] = 0,
  [SSERV_CMD_PROB_CHANGE_SOURCE_FOOTER] = 0,
  [SSERV_CMD_PROB_CLEAR_SOURCE_FOOTER] = 0,
  [SSERV_CMD_PROB_CHANGE_NORMALIZATION] = 0,
  [SSERV_CMD_PROB_CLEAR_NORMALIZATION] = 0,
  [SSERV_CMD_LANG_UPDATE_VERSIONS] = 0,
  [SSERV_CMD_PROB_CLEAR_VARIANTS] = 0,
  [SSERV_CMD_PROB_RANDOM_VARIANTS] = 0,
  [SSERV_CMD_LOGOUT] = 0,
  [SSERV_CMD_HTTP_REQUEST] = 0,

/* subcommands for SSERV_CMD_HTTP_REQUEST */
  [SSERV_CMD_EDITED_CNTS_BACK] = 1,
  [SSERV_CMD_EDITED_CNTS_CONTINUE] = 1,
  [SSERV_CMD_EDITED_CNTS_START_NEW] = 1,
  [SSERV_CMD_LOCKED_CNTS_FORGET] = 1,
  [SSERV_CMD_LOCKED_CNTS_CONTINUE] = 1,
  [SSERV_CMD_USER_FILTER_CHANGE_ACTION] = 1,
  [SSERV_CMD_USER_FILTER_FIRST_PAGE_ACTION] = 1,
  [SSERV_CMD_USER_FILTER_PREV_PAGE_ACTION] = 1,
  [SSERV_CMD_USER_FILTER_NEXT_PAGE_ACTION] = 1,
  [SSERV_CMD_USER_FILTER_LAST_PAGE_ACTION] = 1,
  [SSERV_CMD_USER_JUMP_CONTEST_ACTION] = 1,
  [SSERV_CMD_USER_JUMP_GROUP_ACTION] = 1,
  [SSERV_CMD_USER_BROWSE_MARK_ALL_ACTION] = 1,
  [SSERV_CMD_USER_BROWSE_UNMARK_ALL_ACTION] = 1,
  [SSERV_CMD_USER_BROWSE_TOGGLE_ALL_ACTION] = 1,
  [SSERV_CMD_USER_CREATE_ONE_PAGE] = 1,
  [SSERV_CMD_USER_CREATE_ONE_ACTION] = 1,
  [SSERV_CMD_USER_CREATE_MANY_PAGE] = 1,
  [SSERV_CMD_USER_CREATE_MANY_ACTION] = 1,
  [SSERV_CMD_USER_CREATE_FROM_CSV_PAGE] = 1,
  [SSERV_CMD_USER_CREATE_FROM_CSV_ACTION] = 1,
  [SSERV_CMD_USER_DETAIL_PAGE] = 1,
  [SSERV_CMD_USER_PASSWORD_PAGE] = 1,
  [SSERV_CMD_USER_CHANGE_PASSWORD_ACTION] = 1,
  [SSERV_CMD_USER_CNTS_PASSWORD_PAGE] = 1,
  [SSERV_CMD_USER_CHANGE_CNTS_PASSWORD_ACTION] = 1,
  [SSERV_CMD_USER_CLEAR_FIELD_ACTION] = 1,
  [SSERV_CMD_USER_CREATE_MEMBER_ACTION] = 1,
  [SSERV_CMD_USER_DELETE_MEMBER_PAGE] = 1,
  [SSERV_CMD_USER_DELETE_MEMBER_ACTION] = 1,
  [SSERV_CMD_USER_SAVE_AND_PREV_ACTION] = 1,
  [SSERV_CMD_USER_SAVE_ACTION] = 1,
  [SSERV_CMD_USER_SAVE_AND_NEXT_ACTION] = 1,
  [SSERV_CMD_USER_CANCEL_AND_PREV_ACTION] = 1,
  [SSERV_CMD_USER_CANCEL_ACTION] = 1,
  [SSERV_CMD_USER_CANCEL_AND_NEXT_ACTION] = 1,
  [SSERV_CMD_USER_CREATE_REG_PAGE] = 1,
  [SSERV_CMD_USER_CREATE_REG_ACTION] = 1,
  [SSERV_CMD_USER_EDIT_REG_PAGE] = 1,
  [SSERV_CMD_USER_EDIT_REG_ACTION] = 1,
  [SSERV_CMD_USER_DELETE_REG_PAGE] = 1,
  [SSERV_CMD_USER_DELETE_REG_ACTION] = 1,
  [SSERV_CMD_USER_DELETE_SESSION_ACTION] = 1,
  [SSERV_CMD_USER_DELETE_ALL_SESSIONS_ACTION] = 1,
  [SSERV_CMD_USER_SEL_RANDOM_PASSWD_PAGE] = 1,
  [SSERV_CMD_USER_SEL_RANDOM_PASSWD_ACTION] = 1,
  [SSERV_CMD_USER_SEL_CLEAR_CNTS_PASSWD_PAGE] = 1,
  [SSERV_CMD_USER_SEL_CLEAR_CNTS_PASSWD_ACTION] = 1,
  [SSERV_CMD_USER_SEL_RANDOM_CNTS_PASSWD_PAGE] = 1,
  [SSERV_CMD_USER_SEL_RANDOM_CNTS_PASSWD_ACTION] = 1,
  [SSERV_CMD_USER_SEL_CREATE_REG_PAGE] = 1,
  [SSERV_CMD_USER_SEL_CREATE_REG_ACTION] = 1,
  [SSERV_CMD_USER_SEL_CREATE_REG_AND_COPY_PAGE] = 1,
  [SSERV_CMD_USER_SEL_CREATE_REG_AND_COPY_ACTION] = 1,
  [SSERV_CMD_USER_SEL_DELETE_REG_PAGE] = 1,
  [SSERV_CMD_USER_SEL_DELETE_REG_ACTION] = 1,
  [SSERV_CMD_USER_SEL_CHANGE_REG_STATUS_PAGE] = 1,
  [SSERV_CMD_USER_SEL_CHANGE_REG_STATUS_ACTION] = 1,
  [SSERV_CMD_USER_SEL_CHANGE_REG_FLAGS_PAGE] = 1,
  [SSERV_CMD_USER_SEL_CHANGE_REG_FLAGS_ACTION] = 1,
  [SSERV_CMD_USER_SEL_CANCEL_ACTION] = 1,
  [SSERV_CMD_USER_SEL_VIEW_PASSWD_PAGE] = 1,
  [SSERV_CMD_USER_SEL_VIEW_CNTS_PASSWD_PAGE] = 1,
  [SSERV_CMD_USER_SEL_VIEW_PASSWD_REDIRECT] = 1,
  [SSERV_CMD_USER_SEL_VIEW_CNTS_PASSWD_REDIRECT] = 1,
  [SSERV_CMD_USER_SEL_CREATE_GROUP_MEMBER_PAGE] = 1,
  [SSERV_CMD_USER_SEL_CREATE_GROUP_MEMBER_ACTION] = 1,
  [SSERV_CMD_USER_SEL_DELETE_GROUP_MEMBER_PAGE] = 1,
  [SSERV_CMD_USER_SEL_DELETE_GROUP_MEMBER_ACTION] = 1,
  [SSERV_CMD_USER_IMPORT_CSV_PAGE] = 1,
  [SSERV_CMD_USER_IMPORT_CSV_ACTION] = 1,
  [SSERV_CMD_GROUP_BROWSE_PAGE] = 1,
  [SSERV_CMD_GROUP_FILTER_CHANGE_ACTION] = 1,
  [SSERV_CMD_GROUP_FILTER_FIRST_PAGE_ACTION] = 1,
  [SSERV_CMD_GROUP_FILTER_PREV_PAGE_ACTION] = 1,
  [SSERV_CMD_GROUP_FILTER_NEXT_PAGE_ACTION] = 1,
  [SSERV_CMD_GROUP_FILTER_LAST_PAGE_ACTION] = 1,
  [SSERV_CMD_GROUP_CREATE_PAGE] = 1,
  [SSERV_CMD_GROUP_CREATE_ACTION] = 1,
  [SSERV_CMD_GROUP_MODIFY_PAGE] = 1,
  [SSERV_CMD_GROUP_MODIFY_PAGE_ACTION] = 1,
  [SSERV_CMD_GROUP_MODIFY_ACTION] = 1,
  [SSERV_CMD_GROUP_DELETE_PAGE] = 1,
  [SSERV_CMD_GROUP_DELETE_PAGE_ACTION] = 1,
  [SSERV_CMD_GROUP_DELETE_ACTION] = 1,
  [SSERV_CMD_GROUP_CANCEL_ACTION] = 1,
  [SSERV_CMD_TESTS_MAIN_PAGE] = 1,
  [SSERV_CMD_TESTS_STATEMENT_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_STATEMENT_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_STATEMENT_EDIT_2_ACTION] = 1,
  [SSERV_CMD_TESTS_STATEMENT_EDIT_3_ACTION] = 1,
  [SSERV_CMD_TESTS_STATEMENT_EDIT_4_ACTION] = 1,
  [SSERV_CMD_TESTS_STATEMENT_EDIT_5_ACTION] = 1,
  [SSERV_CMD_TESTS_STATEMENT_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_STATEMENT_DELETE_SAMPLE_ACTION] = 1,
  [SSERV_CMD_TESTS_TESTS_VIEW_PAGE] = 1,
  [SSERV_CMD_TESTS_CHECK_TESTS_PAGE] = 1,
  [SSERV_CMD_TESTS_GENERATE_ANSWERS_PAGE] = 1,
  [SSERV_CMD_TESTS_SOURCE_HEADER_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_SOURCE_HEADER_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_SOURCE_HEADER_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_SOURCE_FOOTER_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_SOURCE_FOOTER_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_SOURCE_FOOTER_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_SOLUTION_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_SOLUTION_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_SOLUTION_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_STYLE_CHECKER_CREATE_PAGE] = 1,
  [SSERV_CMD_TESTS_STYLE_CHECKER_CREATE_ACTION] = 1,
  [SSERV_CMD_TESTS_STYLE_CHECKER_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_STYLE_CHECKER_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_STYLE_CHECKER_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_STYLE_CHECKER_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_CHECKER_CREATE_PAGE] = 1,
  [SSERV_CMD_TESTS_CHECKER_CREATE_ACTION] = 1,
  [SSERV_CMD_TESTS_CHECKER_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_CHECKER_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_CHECKER_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_CHECKER_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_VALUER_CREATE_PAGE] = 1,
  [SSERV_CMD_TESTS_VALUER_CREATE_ACTION] = 1,
  [SSERV_CMD_TESTS_VALUER_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_VALUER_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_VALUER_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_VALUER_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_INTERACTOR_CREATE_PAGE] = 1,
  [SSERV_CMD_TESTS_INTERACTOR_CREATE_ACTION] = 1,
  [SSERV_CMD_TESTS_INTERACTOR_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_INTERACTOR_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_INTERACTOR_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_INTERACTOR_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_CHECKER_CREATE_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_CHECKER_CREATE_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_CHECKER_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_CHECKER_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_CHECKER_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_CHECKER_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_INIT_CREATE_PAGE] = 1,
  [SSERV_CMD_TESTS_INIT_CREATE_ACTION] = 1,
  [SSERV_CMD_TESTS_INIT_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_INIT_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_INIT_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_INIT_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_MAKEFILE_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_MAKEFILE_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_MAKEFILE_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_MAKEFILE_GENERATE_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_MOVE_UP_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_MOVE_DOWN_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_MOVE_TO_SAVED_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_INSERT_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_INSERT_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_EDIT_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_DELETE_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_UPLOAD_ARCHIVE_1_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_CHECK_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_GENERATE_ACTION] = 1,
  [SSERV_CMD_TESTS_SAVED_MOVE_UP_ACTION] = 1,
  [SSERV_CMD_TESTS_SAVED_MOVE_DOWN_ACTION] = 1,
  [SSERV_CMD_TESTS_SAVED_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_SAVED_MOVE_TO_TEST_ACTION] = 1,
  [SSERV_CMD_TESTS_README_CREATE_PAGE] = 1,
  [SSERV_CMD_TESTS_README_EDIT_PAGE] = 1,
  [SSERV_CMD_TESTS_README_DELETE_PAGE] = 1,
  [SSERV_CMD_TESTS_CANCEL_ACTION] = 1,
  [SSERV_CMD_TESTS_CANCEL_2_ACTION] = 1,
  [SSERV_CMD_TESTS_TEST_DOWNLOAD] = 1,
  [SSERV_CMD_TESTS_TEST_UPLOAD_PAGE] = 1,
  [SSERV_CMD_TESTS_TEST_CLEAR_INF_ACTION] = 1,
  [SSERV_CMD_TESTS_MAKE] = 1,
  [SSERV_CMD_USER_MAP_MAIN_PAGE] = 1,
  [SSERV_CMD_USER_MAP_DELETE_ACTION] = 1,
  [SSERV_CMD_USER_MAP_ADD_ACTION] = 1,
  [SSERV_CMD_CAPS_MAIN_PAGE] = 1,
  [SSERV_CMD_CAPS_DELETE_ACTION] = 1,
  [SSERV_CMD_CAPS_ADD_ACTION] = 1,
  [SSERV_CMD_CAPS_EDIT_PAGE] = 1,
  [SSERV_CMD_CAPS_EDIT_SAVE_ACTION] = 1,
  [SSERV_CMD_CAPS_EDIT_CANCEL_ACTION] = 1,
  [SSERV_CMD_EJUDGE_XML_UPDATE_ACTION] = 1,
  [SSERV_CMD_EJUDGE_XML_CANCEL_ACTION] = 1,
  [SSERV_CMD_EJUDGE_XML_MUST_RESTART] = 1,
  [SSERV_CMD_IMPORT_FROM_POLYGON_PAGE] = 1,
  [SSERV_CMD_IMPORT_FROM_POLYGON_ACTION] = 1,
  [SSERV_CMD_DOWNLOAD_PROGRESS_PAGE] = 1,
  [SSERV_CMD_DOWNLOAD_CLEANUP_ACTION] = 1,
  [SSERV_CMD_DOWNLOAD_KILL_ACTION] = 1,
  [SSERV_CMD_DOWNLOAD_CLEANUP_AND_CHECK_ACTION] = 1,
  [SSERV_CMD_DOWNLOAD_CLEANUP_AND_IMPORT_ACTION] = 1,
  [SSERV_CMD_UPDATE_FROM_POLYGON_PAGE] = 1,
  [SSERV_CMD_UPDATE_FROM_POLYGON_ACTION] = 1,
  [SSERV_CMD_IMPORT_PROBLEMS_BATCH_ACTION] = 1,
  [SSERV_CMD_CREATE_CONTEST_BATCH_ACTION] = 1,
  [SSERV_CMD_IMPORT_CONTEST_FROM_POLYGON_PAGE] = 1,

  [SSERV_CMD_LOGIN_PAGE] = 1,
  [SSERV_CMD_MAIN_PAGE] = 1,
  [SSERV_CMD_CONTEST_PAGE] = 1,
  [SSERV_CMD_CONTEST_XML_PAGE] = 1,
  [SSERV_CMD_SERVE_CFG_PAGE] = 1,
  [SSERV_CMD_CREATE_CONTEST_PAGE] = 1,
  [SSERV_CMD_CREATE_CONTEST_2_ACTION] = 1,
  [SSERV_CMD_CONTEST_ALREADY_EDITED_PAGE] = 1,
  [SSERV_CMD_CONTEST_LOCKED_PAGE] = 1,
  [SSERV_CMD_CHECK_TESTS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_PERMISSIONS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_REGISTER_ACCESS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_USERS_ACCESS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_MASTER_ACCESS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_JUDGE_ACCESS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_TEAM_ACCESS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_SERVE_CONTROL_ACCESS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_USER_FIELDS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_CONTESTANT_FIELDS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_RESERVE_FIELDS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_COACH_FIELDS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_ADVISOR_FIELDS_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_GUEST_FIELDS_PAGE] = 1,
  [SSERV_CMD_CNTS_START_EDIT_ACTION] = 1,
  [SSERV_CMD_CNTS_EDIT_CUR_CONTEST_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_CONTEST_START_CMD_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_CONTEST_STOP_CMD_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_STAND_HEADER_FILE_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_STAND_FOOTER_FILE_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_STAND2_HEADER_FILE_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_STAND2_FOOTER_FILE_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_PLOG_HEADER_FILE_PAGE] = 1,
  [SSERV_CMD_GLOB_EDIT_PLOG_FOOTER_FILE_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_USERS_HEADER_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_USERS_FOOTER_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_COPYRIGHT_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_WELCOME_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_REG_WELCOME_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_REGISTER_EMAIL_FILE_PAGE] = 1,
  [SSERV_CMD_CNTS_RELOAD_FILE_ACTION] = 1,
  [SSERV_CMD_CNTS_SAVE_FILE_ACTION] = 1,
  [SSERV_CMD_CNTS_CLEAR_FILE_ACTION] = 1,
  [SSERV_CMD_CNTS_EDIT_CUR_GLOBAL_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_CUR_LANGUAGE_PAGE] = 1,
  [SSERV_CMD_CNTS_EDIT_CUR_PROBLEM_PAGE] = 1,
  [SSERV_CMD_CNTS_START_EDIT_PROBLEM_ACTION] = 1,
  [SSERV_CMD_CNTS_START_EDIT_VARIANT_ACTION] = 1,
  [SSERV_CMD_CNTS_EDIT_CUR_VARIANT_PAGE] = 1,
  [SSERV_CMD_CNTS_NEW_SERVE_CFG_PAGE] = 1,
  [SSERV_CMD_CNTS_COMMIT_PAGE] = 1,
  [SSERV_CMD_USER_BROWSE_PAGE] = 1,
  [SSERV_CMD_USER_BROWSE_DATA] = 1,
  [SSERV_CMD_GET_CONTEST_LIST] = 1,
  [SSERV_CMD_CNTS_SAVE_BASIC_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_FLAGS_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_REGISTRATION_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_TIMING_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_URLS_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_HEADERS_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_ATTRS_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_NOTIFICATIONS_FORM] = 1,
  [SSERV_CMD_CNTS_SAVE_ADVANCED_FORM] = 1,
  [SSERV_CMD_GLOB_SAVE_MAIN_FORM] = 1,
  [SSERV_CMD_GLOB_SAVE_CAPABILITIES_FORM] = 1,
  [SSERV_CMD_GLOB_SAVE_FILES_FORM] = 1,
  [SSERV_CMD_GLOB_SAVE_QUOTAS_FORM] = 1,
  [SSERV_CMD_GLOB_SAVE_URLS_FORM] = 1,
  [SSERV_CMD_GLOB_SAVE_ATTRS_FORM] = 1,
  [SSERV_CMD_GLOB_SAVE_ADVANCED_FORM] = 1,
};
