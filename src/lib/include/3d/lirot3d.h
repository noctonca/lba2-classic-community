#pragma once

#include <3d/datamat.h>
#include <system/adeline_types.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
typedef void(Func_LongInverseRotatePoint)(TYPE_MAT *Mat, S32 x, S32 y, S32 z);

// -----------------------------------------------------------------------------
extern Func_LongInverseRotatePoint *LongInverseRotatePoint;

// -----------------------------------------------------------------------------
#define LongWorldInverseRotatePoint(x, y, z) \
    LongInverseRotatePoint(&MatriceWorld, x, y, z)

// =============================================================================
#ifdef __cplusplus
}
#endif
