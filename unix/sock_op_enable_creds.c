/* -*- mode: c -*- */
/* $Id$ */

/* Copyright (C) 2008 Alexander Chernov <cher@ejudge.ru> */

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

#include "config.h"

#include "sock_op.h"

#include "errlog.h"

#include <reuse/osdeps.h>

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

int
sock_op_enable_creds(int sock_fd)
{
#if HAVE_SO_PASSCRED - 0 == 1
  int val = 1;
  if (setsockopt(sock_fd, SOL_SOCKET, SO_PASSCRED, &val, sizeof(val)) < 0) {
    err("%s: setsockopt() failed: %s", __FUNCTION__, os_ErrorMsg());
    return -1;
  }
#endif
  return 0;
}

/*
 * Local variables:
 *  compile-command: "make -C .."
 *  c-font-lock-extra-types: ("\\sw+_t" "FILE")
 * End:
 */
