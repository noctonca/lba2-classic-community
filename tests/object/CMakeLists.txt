set(_OBJ_ASM_DIR ${CMAKE_SOURCE_DIR}/src/lib/object)
set(_OBJ_ASM_INC ${CMAKE_SOURCE_DIR}/src/lib/include)

add_asm_cpp_test(
    NAME test_aff_obj  TEST_SOURCE test_aff_obj.cpp
    ASM_SOURCE ${_OBJ_ASM_DIR}/aff_obj.asm
    RENAME_SYMS BodyDisplay BodyDisplay_AlphaBeta ObjectDisplay ObjPtrMap Obj_ListProjectedPoints TransFctBody Obj_ListRotatedPoints QuickSort QuickSortInv lBody Off_Sort Nb_Sort PosXWr PosYWr PosZWr TabMat ListLights ListSort ListFillPoly PtrTextures
    ASM_DEPS ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polyline.asm ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polydisc.asm
    ASM_DEP_RENAME_SYMS Line LineZBuf LineZBufNZW Line_A Fill_Sphere
    LIBS obj 3D poly svg sys SDL3::SDL3
    ASM_INCLUDE_DIRS ${_OBJ_ASM_INC}
)
# aff_obj.asm references Fill_PolyFast, Fill_Sphere, Line_A (cross-module ASM procs)
target_link_options(test_aff_obj PRIVATE -Wl,--unresolved-symbols=ignore-in-object-files)
