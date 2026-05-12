#include <anim/clear.h>
#include <system/debug_traces.h>
#include <string.h>

void ObjectClear(T_OBJ_3D *obj) {
    LIB386_TRACE_CPP("ObjectClear", "1", "obj=%p", (void *)obj);
    memset(obj, 0, sizeof(T_OBJ_3D));

    obj->Body.Num = -1;
    obj->NextBody.Num = -1;
    obj->Texture = (void *)-1;
    obj->NextTexture = (void *)-1;
    obj->Anim.Num = -1;
}
