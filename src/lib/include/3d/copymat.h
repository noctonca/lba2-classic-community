#pragma once

#include <3d/datamat.h>
#include <system/adeline_types.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
typedef void(Func_CopyFlipMatrix)(TYPE_MAT *MatDst, TYPE_MAT *MatSrc);

// -----------------------------------------------------------------------------
extern Func_CopyFlipMatrix *CopyMatrix; ///< Do Not call from C

// =============================================================================
#ifdef __cplusplus
}
#endif
