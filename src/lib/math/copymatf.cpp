#include <3d/copymat.h>
#include <string.h>
#include <system/debug_traces.h>

void CopyMatrixF(TYPE_MAT *MatDst, TYPE_MAT *MatSrc) {
    LIB386_TRACE_CPP("CopyMatrixF", "1", "Dst=%p Src=%p", (void *)MatDst, (void *)MatSrc);
    memcpy(MatDst, MatSrc, sizeof(TYPE_MAT));
}

// -----------------------------------------------------------------------------
Func_CopyFlipMatrix *CopyMatrix = CopyMatrixF; ///< Do Not call from C
