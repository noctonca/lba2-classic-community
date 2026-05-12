set(_ANIM_ASM_DIR ${CMAKE_SOURCE_DIR}/src/lib/anim)
set(_ANIM_ASM_INC ${CMAKE_SOURCE_DIR}/src/lib/include)
set(_ANIM_LIBS ani obj 3D poly svg sys SDL3::SDL3)

# .model SMALL ASM files are automatically patched to FLAT at build time.
add_asm_cpp_test(NAME test_clear      TEST_SOURCE test_clear.cpp      ASM_SOURCE ${_ANIM_ASM_DIR}/clear.asm      RENAME_SYMS ObjectClear              LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_body       TEST_SOURCE test_body.cpp       ASM_SOURCE ${_ANIM_ASM_DIR}/body.asm       RENAME_SYMS ObjectInitBody           LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
# texture.asm: proc uses Watcom register calling convention (parm [ebx] [eax]).
add_asm_cpp_test(NAME test_texture    TEST_SOURCE test_texture.cpp    ASM_SOURCE ${_ANIM_ASM_DIR}/texture.asm    RENAME_SYMS ObjectInitTexture           LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_anim       TEST_SOURCE test_anim.cpp       ASM_SOURCE ${_ANIM_ASM_DIR}/anim.asm       RENAME_SYMS ObjectInitAnim           LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_frame      TEST_SOURCE test_frame.cpp      ASM_SOURCE ${_ANIM_ASM_DIR}/frame.asm      RENAME_SYMS ObjectSetFrame           LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_intanim    TEST_SOURCE test_intanim.cpp    ASM_SOURCE ${_ANIM_ASM_DIR}/intanim.asm    RENAME_SYMS ObjectSetInterAnim       LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_interdep   TEST_SOURCE test_interdep.cpp   ASM_SOURCE ${_ANIM_ASM_DIR}/interdep.asm   RENAME_SYMS ObjectSetInterDep        LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_intframe   TEST_SOURCE test_intframe.cpp   ASM_SOURCE ${_ANIM_ASM_DIR}/intframe.asm   RENAME_SYMS ObjectSetInterFrame      LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_stoframe   TEST_SOURCE test_stoframe.cpp   ASM_SOURCE ${_ANIM_ASM_DIR}/stoframe.asm   RENAME_SYMS ObjectStoreFrame         LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
add_asm_cpp_test(NAME test_libinit    TEST_SOURCE test_libinit.cpp    ASM_SOURCE ${_ANIM_ASM_DIR}/libinit.asm    RENAME_SYMS InitObjects ClearObjects Lib3DBufferAnim EndLib3DBufferAnim PtrLib3DBufferAnim TransFctAnim  LIBS ${_ANIM_LIBS}  ASM_INCLUDE_DIRS ${_ANIM_ASM_INC})
