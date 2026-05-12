#pragma once

#include <3d/datamat.h>
#include <system/adeline_types.h>

// -----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
//****************************************************************************
typedef void(Func_LongRotatePoint)(TYPE_MAT *Mat, S32 x, S32 y, S32 z);

extern Func_LongRotatePoint *LongRotatePoint;

// -----------------------------------------------------------------------------
#define LongWorldRotatePoint(x, y, z) LongRotatePoint(&MatriceWorld, x, y, z)

// =============================================================================
#ifdef __cplusplus
}
#endif
