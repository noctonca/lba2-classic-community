#include <anim/intanim.h>

#include <anim.h>
#include <anim/intframe.h>
#include <anim/interdep.h>
#include <system/debug_traces.h>

S32 ObjectSetInterAnim(T_OBJ_3D *obj) {
    LIB386_TRACE_CPP("ObjectSetInterAnim", "1", "obj=%p", (void *)obj);
    S32 status = ObjectSetInterDep(obj);
    if ((status & FLAG_CHANGE)     // any change?
        && !(status & FLAG_FRAME)) // frame ?
    {
        ObjectSetInterFrame(obj);
    }

    return status;
}
