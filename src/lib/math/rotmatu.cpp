#include <3d/rotmat.h>
#include <3d/imatstd.h>
#include <3d/mulmat.h>
#include <system/debug_traces.h>

void RotateMatrixU(TYPE_MAT *MatDst, TYPE_MAT *MatSrc,
                   S32 x, S32 y, S32 z) {
    LIB386_TRACE_CPP("RotateMatrixU", "1", "Dst=%p Src=%p a=%d b=%d g=%d", (void *)MatDst, (void *)MatSrc, x, y, z);
    InitMatrixStd(&MatrixLib2, x, y, z);
    MulMatrix(MatDst, MatSrc, &MatrixLib2);
}

// -----------------------------------------------------------------------------
Func_RotateMatrix *RotateMatrix = RotateMatrixU;
