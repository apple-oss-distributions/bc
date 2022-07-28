/*
 * *****************************************************************************
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2018-2021 Gavin D. Howard and contributors.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * *****************************************************************************
 *
 * All bc status codes.
 *
 */

#ifndef BC_STATUS_H
#define BC_STATUS_H

#include <stdint.h>

#ifndef BC_ENABLED
#define BC_ENABLED (1)
#endif // BC_ENABLED

#ifndef DC_ENABLED
#define DC_ENABLED (1)
#endif // DC_ENABLED

#if BC_ENABLE_AFL
#ifndef __AFL_HAVE_MANUAL_CONTROL
#error Must compile with afl-clang-fast for fuzzing
#endif // __AFL_HAVE_MANUAL_CONTROL
#endif // BC_ENABLE_AFL

#ifndef BC_ENABLE_MEMCHECK
#define BC_ENABLE_MEMCHECK (0)
#endif // BC_ENABLE_MEMCHECK

#include <bcl.h>

typedef enum BcStatus {

	BC_STATUS_SUCCESS = 0,
	BC_STATUS_ERROR_MATH,
	BC_STATUS_ERROR_PARSE,
	BC_STATUS_ERROR_EXEC,
	BC_STATUS_ERROR_FATAL,
	BC_STATUS_EOF,
	BC_STATUS_QUIT,

} BcStatus;

typedef enum BcErr {

	BC_ERR_MATH_NEGATIVE,
	BC_ERR_MATH_NON_INTEGER,
	BC_ERR_MATH_OVERFLOW,
	BC_ERR_MATH_DIVIDE_BY_ZERO,

	BC_ERR_FATAL_ALLOC_ERR,
	BC_ERR_FATAL_IO_ERR,
	BC_ERR_FATAL_FILE_ERR,
	BC_ERR_FATAL_BIN_FILE,
	BC_ERR_FATAL_PATH_DIR,
	BC_ERR_FATAL_OPTION,
	BC_ERR_FATAL_OPTION_NO_ARG,
	BC_ERR_FATAL_OPTION_ARG,

	BC_ERR_EXEC_IBASE,
	BC_ERR_EXEC_OBASE,
	BC_ERR_EXEC_SCALE,
	BC_ERR_EXEC_READ_EXPR,
	BC_ERR_EXEC_REC_READ,
	BC_ERR_EXEC_TYPE,

	BC_ERR_EXEC_STACK,

	BC_ERR_EXEC_PARAMS,
	BC_ERR_EXEC_UNDEF_FUNC,
	BC_ERR_EXEC_VOID_VAL,

	BC_ERR_PARSE_EOF,
	BC_ERR_PARSE_CHAR,
	BC_ERR_PARSE_STRING,
	BC_ERR_PARSE_COMMENT,
	BC_ERR_PARSE_TOKEN,
#if BC_ENABLED
	BC_ERR_PARSE_EXPR,
	BC_ERR_PARSE_EMPTY_EXPR,
	BC_ERR_PARSE_PRINT,
	BC_ERR_PARSE_FUNC,
	BC_ERR_PARSE_ASSIGN,
	BC_ERR_PARSE_NO_AUTO,
	BC_ERR_PARSE_DUP_LOCAL,
	BC_ERR_PARSE_BLOCK,
	BC_ERR_PARSE_RET_VOID,
	BC_ERR_PARSE_REF_VAR,

	BC_ERR_POSIX_NAME_LEN,
	BC_ERR_POSIX_COMMENT,
	BC_ERR_POSIX_KW,
	BC_ERR_POSIX_DOT,
	BC_ERR_POSIX_RET,
	BC_ERR_POSIX_BOOL,
	BC_ERR_POSIX_REL_POS,
	BC_ERR_POSIX_MULTIREL,
	BC_ERR_POSIX_FOR,
	BC_ERR_POSIX_EXP_NUM,
	BC_ERR_POSIX_REF,
	BC_ERR_POSIX_VOID,
	BC_ERR_POSIX_BRACE,
#endif // BC_ENABLED

	BC_ERR_NELEMS,

#if BC_ENABLED
	BC_ERR_POSIX_START = BC_ERR_POSIX_NAME_LEN,
	BC_ERR_POSIX_END = BC_ERR_POSIX_BRACE,
#endif // BC_ENABLED

} BcErr;

#define BC_ERR_IDX_MATH (0)
#define BC_ERR_IDX_PARSE (1)
#define BC_ERR_IDX_EXEC (2)
#define BC_ERR_IDX_FATAL (3)
#define BC_ERR_IDX_NELEMS (4)

#if BC_ENABLED
#define BC_ERR_IDX_WARN (BC_ERR_IDX_NELEMS)
#endif // BC_ENABLED

#endif // BC_STATUS_H