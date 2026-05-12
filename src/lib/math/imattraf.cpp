#include <3d/imattra.h>
#include <system/debug_traces.h>

void InitMatrixTransF(TYPE_MAT *MatDst, S32 tx, S32 ty, S32 tz) {
    LIB386_TRACE_CPP("InitMatrixTransF", "1", "Dst=%p tx=%d ty=%d tz=%d", (void *)MatDst, tx, ty, tz);
    MatDst->F.TX = (float)tx;
    MatDst->F.TY = (float)ty;
    MatDst->F.TZ = (float)tz;
}

// -----------------------------------------------------------------------------
Func_InitMatrixTrans *InitMatrixTrans = InitMatrixTransF; ///< Do Not call from C
