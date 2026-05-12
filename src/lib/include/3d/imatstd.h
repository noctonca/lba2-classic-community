#pragma once

#include <3d/datamat.h>
#include <system/adeline_types.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
typedef void(Func_InitMatrix)(TYPE_MAT *MatDst, S32 alpha, S32 beta, S32 gamma);

extern Func_InitMatrix *InitMatrixStd;

// =============================================================================
#ifdef __cplusplus
}
#endif
