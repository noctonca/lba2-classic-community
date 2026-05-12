set(_SVGA_ASM_DIR ${CMAKE_SOURCE_DIR}/src/render/software/svga)
set(_SVGA_ASM_INC ${CMAKE_SOURCE_DIR}/src/lib/include)
set(_SVGA_LIBS svg sys poly SDL3::SDL3)

# .model SMALL ASM files are automatically patched to FLAT at build time.
add_asm_cpp_test(NAME test_box        TEST_SOURCE test_box.cpp        ASM_SOURCE ${_SVGA_ASM_DIR}/box.asm        RENAME_SYMS Box                         LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
# CLRBOXF: SetClearColor uses Watcom register calling convention (parm [eax]).
# ClearBoxF is C-adapted with PROC params — callable directly.
add_asm_cpp_test(NAME test_clrboxf    TEST_SOURCE test_clrboxf.cpp    ASM_SOURCE ${_SVGA_ASM_DIR}/clrboxf.asm    RENAME_SYMS ClearBox SetClearColor ClearColor ClearBoxF
    LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_font       TEST_SOURCE test_font.cpp       ASM_SOURCE ${_SVGA_ASM_DIR}/font.asm       RENAME_SYMS SizeFont CarFont Font PtrFont InterLeave InterSpace  LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_affstr     TEST_SOURCE test_affstr.cpp     ASM_SOURCE ${_SVGA_ASM_DIR}/affstr.asm     RENAME_SYMS AffString SizeChar TextInk TextPaper  LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})

# blitboxf.cpp contains only commented ASM — no C implementation, placeholder.
add_asm_cpp_test(NAME test_blitboxf   TEST_SOURCE test_blitboxf.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/blitboxf.asm   RENAME_SYMS BlitBox BlitBoxF                LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})

add_asm_cpp_test(NAME test_calcmask   TEST_SOURCE test_calcmask.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/calcmask.asm   RENAME_SYMS CalcGraphMsk                LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_copymask   TEST_SOURCE test_copymask.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/copymask.asm   RENAME_SYMS CopyMask                    LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_graph      TEST_SOURCE test_graph.cpp      ASM_SOURCE ${_SVGA_ASM_DIR}/graph.asm      RENAME_SYMS AffGraph GetBoxGraph         LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_mask       TEST_SOURCE test_mask.cpp       ASM_SOURCE ${_SVGA_ASM_DIR}/mask.asm       RENAME_SYMS AffMask ColMask              LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_savblock   TEST_SOURCE test_savblock.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/savblock.asm   RENAME_SYMS SaveBlock                   LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_resblock   TEST_SOURCE test_resblock.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/resblock.asm   RENAME_SYMS RestoreBlock                LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_cpyblock   TEST_SOURCE test_cpyblock.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/cpyblock.asm   RENAME_SYMS CopyBlock                   LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_cpybloci   TEST_SOURCE test_cpybloci.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/cpybloci.asm   RENAME_SYMS CopyBlockIncrust            LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_scalebox   TEST_SOURCE test_scalebox.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/scalebox.asm   RENAME_SYMS ScaleBox                    LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_scalespi   TEST_SOURCE test_scalespi.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/scalespi.asm   RENAME_SYMS ScaleSprite                 LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
add_asm_cpp_test(NAME test_scalespt   TEST_SOURCE test_scalespt.cpp   ASM_SOURCE ${_SVGA_ASM_DIR}/scalespt.asm   RENAME_SYMS ScaleSpriteTransp           LIBS ${_SVGA_LIBS}  ASM_INCLUDE_DIRS ${_SVGA_ASM_INC})
