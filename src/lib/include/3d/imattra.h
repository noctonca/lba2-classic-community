#pragma once

#include <3d/datamat.h>
#include <system/adeline_types.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
typedef void(Func_InitMatrixTrans)(TYPE_MAT *MatDst, S32 tx, S32 ty, S32 tz);

// -----------------------------------------------------------------------------
extern Func_InitMatrixTrans *InitMatrixTrans; ///< Do Not call from C

// =============================================================================
#ifdef __cplusplus
}
#endif
