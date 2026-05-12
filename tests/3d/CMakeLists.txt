set(_3D_ASM_DIR ${CMAKE_SOURCE_DIR}/src/lib/math)
set(_3D_ASM_INC ${CMAKE_SOURCE_DIR}/src/lib/include)

# All tests are ASM-vs-CPP equivalence.  .model SMALL ASM files are
# automatically patched to .model FLAT at build time (see patch_asm_flat.cmake).
#
# Many 3D/ ASM procs use Watcom register calling convention
# (#pragma aux parm [edi] [esi] [ebx]) instead of C stack parameters.
# These SEGFAULT when called from C because the parameters end up on the
# stack instead of in registers.  A few procs with proper PROC parameter
# declarations (GETANG2D, SQRROOT, REGLE3) do work.

# ── Data tables ───────────────────────────────────────────────────────────
add_asm_cpp_test(NAME test_sintab   TEST_SOURCE test_sintab.cpp   ASM_SOURCE ${_3D_ASM_DIR}/sintab.asm   RENAME_SYMS SinTab CosTab                                     LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_sintabf  TEST_SOURCE test_sintabf.cpp  ASM_SOURCE ${_3D_ASM_DIR}/sintabf.asm  RENAME_SYMS SinTabF CosTabF                                    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_tantab   TEST_SOURCE test_tantab.cpp   ASM_SOURCE ${_3D_ASM_DIR}/tantab.asm   RENAME_SYMS TanTab                                             LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})

# ── Pure math ─────────────────────────────────────────────────────────────
add_asm_cpp_test(NAME test_getang2d  TEST_SOURCE test_getang2d.cpp  ASM_SOURCE ${_3D_ASM_DIR}/getang2d.asm  RENAME_SYMS GetAngleVector2D                                LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
# GetAngleVector3D calls GetAngleVector2D+QSqr internally.
# STRIP_C_ADAPT reverts all procs to bare Watcom register convention so
# internal calls work correctly.  Callees are included as renamed deps.
add_asm_cpp_test(NAME test_getang3d  TEST_SOURCE test_getang3d.cpp  ASM_SOURCE ${_3D_ASM_DIR}/getang3d.asm  RENAME_SYMS GetAngleVector3D
    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC}
    STRIP_C_ADAPT
    ASM_DEPS ${_3D_ASM_DIR}/getang2d.asm ${_3D_ASM_DIR}/sqrroot.asm
    ASM_DEP_RENAME_SYMS GetAngleVector2D Sqr QSqr)
# Sqr/QSqr: C-adapted PROC has "uses eax" which destroys the return value.
# STRIP_C_ADAPT reverts to bare Watcom procs.
add_asm_cpp_test(NAME test_sqrroot   TEST_SOURCE test_sqrroot.cpp   ASM_SOURCE ${_3D_ASM_DIR}/sqrroot.asm   RENAME_SYMS Sqr QSqr
    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC}
    STRIP_C_ADAPT)
add_asm_cpp_test(NAME test_regle3    TEST_SOURCE test_regle3.cpp    ASM_SOURCE ${_3D_ASM_DIR}/regle3.asm    RENAME_SYMS RegleTrois BoundRegleTrois                       LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})

# ── Matrix ops ────────────────────────────────────────────────────────────
add_asm_cpp_test(NAME test_copymatf   TEST_SOURCE test_copymatf.cpp   ASM_SOURCE ${_3D_ASM_DIR}/copymatf.asm   RENAME_SYMS CopyMatrix CopyMatrixF                       LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
# InitMatrixStdF uses SinTabF[register] indexing — needs sintabf.asm data tables.
# ASM_DEP_RENAME_SYMS avoids overriding CPP's pointer-typed SinTabF/CosTabF.
add_asm_cpp_test(NAME test_imatstdf   TEST_SOURCE test_imatstdf.cpp   ASM_SOURCE ${_3D_ASM_DIR}/imatstdf.asm   RENAME_SYMS InitMatrixStd InitMatrix InitMatrixStdF
    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC}
    ASM_DEPS ${_3D_ASM_DIR}/sintabf.asm
    ASM_DEP_RENAME_SYMS SinTabF CosTabF)
add_asm_cpp_test(NAME test_imattraf   TEST_SOURCE test_imattraf.cpp   ASM_SOURCE ${_3D_ASM_DIR}/imattraf.asm   RENAME_SYMS InitMatrixTrans InitMatrixTransF               LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_mulmatf    TEST_SOURCE test_mulmatf.cpp    ASM_SOURCE ${_3D_ASM_DIR}/mulmatf.asm    RENAME_SYMS MulMatrix MulMatrixF                           LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
# RotateMatrixU calls [InitMatrixStd]+jmp [MulMatrix] (non-leaf, Watcom register convention).
# Include callee ASM deps so function pointers resolve to Watcom-convention procs.
add_asm_cpp_test(NAME test_rotmatu    TEST_SOURCE test_rotmatu.cpp    ASM_SOURCE ${_3D_ASM_DIR}/rotmatu.asm    RENAME_SYMS RotateMatrix RotateMatrixU
    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC}
    ASM_DEPS ${_3D_ASM_DIR}/imatstdf.asm ${_3D_ASM_DIR}/mulmatf.asm ${_3D_ASM_DIR}/sintabf.asm
    ASM_DEP_RENAME_SYMS InitMatrixStd InitMatrix InitMatrixStdF MulMatrix MulMatrixF SinTabF CosTabF)

# ── Rotation & transform ─────────────────────────────────────────────────
# LongRotateF uses SinTabF/CosTabF[register] indexing — needs sintabf.asm data tables.
# STRIP_C_ADAPT reverts to bare Watcom proc; ASM_DEP_RENAME_SYMS avoids overriding CPP SinTabF.
add_asm_cpp_test(NAME test_lrot2df    TEST_SOURCE test_lrot2df.cpp    ASM_SOURCE ${_3D_ASM_DIR}/lrot2df.asm    RENAME_SYMS LongRotate Rotate LongRotateF
    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC}
    STRIP_C_ADAPT
    ASM_DEPS ${_3D_ASM_DIR}/sintabf.asm
    ASM_DEP_RENAME_SYMS SinTabF CosTabF)
add_asm_cpp_test(NAME test_lrot3df    TEST_SOURCE test_lrot3df.cpp    ASM_SOURCE ${_3D_ASM_DIR}/lrot3df.asm    RENAME_SYMS LongRotatePoint RotatePoint RotatePointNoMMX LongRotatePointF  LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_lirot3df   TEST_SOURCE test_lirot3df.cpp   ASM_SOURCE ${_3D_ASM_DIR}/lirot3df.asm   RENAME_SYMS LongInverseRotatePoint LongInverseRotatePointF LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_rotralif   TEST_SOURCE test_rotralif.cpp   ASM_SOURCE ${_3D_ASM_DIR}/rotralif.asm   RENAME_SYMS RotTransList RotTransListF                     LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
# RotateVector calls [InitMatrixStd]+jmp [LongRotatePoint] (non-leaf, Watcom register convention).
# Include callee ASM deps so function pointers resolve to Watcom-convention procs.
add_asm_cpp_test(NAME test_rotvect    TEST_SOURCE test_rotvect.cpp    ASM_SOURCE ${_3D_ASM_DIR}/rotvect.asm    RENAME_SYMS RotateVector
    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC}
    ASM_DEPS ${_3D_ASM_DIR}/imatstdf.asm ${_3D_ASM_DIR}/lrot3df.asm ${_3D_ASM_DIR}/sintabf.asm
    ASM_DEP_RENAME_SYMS InitMatrixStd InitMatrix InitMatrixStdF LongRotatePoint RotatePoint RotatePointNoMMX LongRotatePointF SinTabF CosTabF)

# ── Projection ────────────────────────────────────────────────────────────
# proj.asm references LongProjectPoint3DF/ProjectList3DF (ASM-only symbols, not in CPP lib).
add_asm_cpp_test(NAME test_proj       TEST_SOURCE test_proj.cpp       ASM_SOURCE ${_3D_ASM_DIR}/proj.asm       RENAME_SYMS SetProjection SetIsoProjection                  LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
target_link_options(test_proj PRIVATE -Wl,--unresolved-symbols=ignore-in-object-files)
add_asm_cpp_test(NAME test_lproj3df   TEST_SOURCE test_lproj3df.cpp   ASM_SOURCE ${_3D_ASM_DIR}/lproj3df.asm   RENAME_SYMS LongProjectPoint3D LongProjectPoint LongProjectPoint3DF  LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_lprojiso   TEST_SOURCE test_lprojiso.cpp   ASM_SOURCE ${_3D_ASM_DIR}/lprojiso.asm   RENAME_SYMS LongProjectPointIso                            LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_prli3df    TEST_SOURCE test_prli3df.cpp    ASM_SOURCE ${_3D_ASM_DIR}/prli3df.asm    RENAME_SYMS ProjectList3D ProjectList ProjectList3DF        LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})
add_asm_cpp_test(NAME test_prliiso    TEST_SOURCE test_prliiso.cpp    ASM_SOURCE ${_3D_ASM_DIR}/prliiso.asm    RENAME_SYMS ProjectListIso                                 LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC})

# ── Lighting — LightListF calls LongInverseRotatePointF (Watcom register convention).
# Include lirot3df.asm as dep so the direct call resolves to ASM Watcom proc.
add_asm_cpp_test(NAME test_litlistf   TEST_SOURCE test_litlistf.cpp   ASM_SOURCE ${_3D_ASM_DIR}/litlistf.asm   RENAME_SYMS LightList LightListF
    LIBS 3D sys  ASM_INCLUDE_DIRS ${_3D_ASM_INC}
    ASM_DEPS ${_3D_ASM_DIR}/lirot3df.asm
    ASM_DEP_RENAME_SYMS LongInverseRotatePoint LongInverseRotatePointF)
