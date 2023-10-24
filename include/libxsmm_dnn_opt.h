/******************************************************************************
* Copyright (c) Intel Corporation - All rights reserved.                      *
* This file is part of the LIBXSMM library.                                   *
*                                                                             *
* For information on the license, see the LICENSE file.                       *
* Further information: https://github.com/libxsmm/libxsmm-dnn/                *
* SPDX-License-Identifier: BSD-3-Clause                                       *
******************************************************************************/
/* Alexander Heinecke (Intel Corp.)
******************************************************************************/
#ifndef LIBXSMM_DNN_OPT_H
#define LIBXSMM_DNN_OPT_H

#include <libxsmm_utils.h>
#include <libxsmm.h>

typedef struct libxsmm_dnn_opt_config {
  libxsmm_blasint C;
  libxsmm_blasint K;
  libxsmm_blasint bc;
  libxsmm_blasint bk;
  libxsmm_blasint threads;
  float           lr;
  size_t          scratch_size;
  libxsmm_barrier* barrier;
} libxsmm_dnn_opt_config;

LIBXSMM_API libxsmm_dnn_opt_config setup_libxsmm_dnn_opt(libxsmm_blasint C, libxsmm_blasint K, libxsmm_blasint bc, libxsmm_blasint bk,
                           libxsmm_blasint threads, float lr, libxsmm_datatype datatype_in,
                           libxsmm_datatype datatype_out, libxsmm_datatype datatype_comp);

LIBXSMM_API void libxsmm_dnn_opt_exec_f32( libxsmm_dnn_opt_config cfg, float* wt_ptr, const float* delwt_ptr, int start_tid, int my_tid, void* scratch );

LIBXSMM_API void libxsmm_dnn_opt_exec_bf16( libxsmm_dnn_opt_config cfg, libxsmm_bfloat16* wt_ptr, float* master_wt_ptr, const libxsmm_bfloat16* delwt_ptr, int start_tid, int my_tid, void* scratch );

#endif
