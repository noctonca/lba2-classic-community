# ─────────────────────────────────────────────────────────────────────────────
# tests/SNAPSHOT/CMakeLists.txt
#
# Builds the standalone polyrec replay programs:
#   - replay_polyrec_asm  (ASM polygon rendering path)
#   - replay_polyrec_cpp  (CPP polygon rendering path)
#
# Then registers one CTest per .lba2polyrec fixture in tests/SNAPSHOT/fixtures/.
# ─────────────────────────────────────────────────────────────────────────────

message(STATUS "POLYREC: Configuring replay tests")
message(STATUS "POLYREC: CMAKE_ASM_MASM_COMPILER = ${CMAKE_ASM_MASM_COMPILER}")
message(STATUS "POLYREC: CMAKE_ASM_MASM_FLAGS = ${CMAKE_ASM_MASM_FLAGS}")

# ── Collect ALL ASM files from LIB386/ ──────────────────────────────────────
set(LIB386_DIR "${CMAKE_SOURCE_DIR}/src")

set(LIB386_ASM_FILES
    # 3D/
    ${CMAKE_SOURCE_DIR}/src/lib/math/copymatf.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/getang2d.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/getang3d.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/imattraf.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/imatstdf.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/litlistf.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/lirot3df.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/lprojiso.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/lproj3df.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/lrot2df.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/lrot3df.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/mulmatf.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/prli3df.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/prliiso.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/proj.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/regle3.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/rotmatu.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/rotvect.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/rotralif.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/sintab.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/sintabf.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/sqrroot.asm
    ${CMAKE_SOURCE_DIR}/src/lib/math/tantab.asm
    # ANIM/
    ${CMAKE_SOURCE_DIR}/src/lib/anim/anim.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/body.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/clear.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/frame.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/intanim.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/intframe.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/interdep.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/libinit.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/stoframe.asm
    ${CMAKE_SOURCE_DIR}/src/lib/anim/texture.asm
    # MENU/
    ${CMAKE_SOURCE_DIR}/src/lib/menu/sort.asm
    # OBJECT/
    ${CMAKE_SOURCE_DIR}/src/lib/object/aff_obj.asm
    # pol_work/
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/poly.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polyclip.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polydisc.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polyflat.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polygtex.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polygour.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polyline.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polytext.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polytexz.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polytzf.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/polytzg.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/poly_jmp.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/pol_work/testvuef.asm
    # SVGA/
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/affstr.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/blitboxf.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/box.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/calcmask.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/clrboxf.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/copymask.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/cpyblock.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/cpybloci.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/font.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/graph.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/mask.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/resblock.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/savblock.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/scalebox.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/scalespi.asm
    ${CMAKE_SOURCE_DIR}/src/render/software/svga/scalespt.asm
    # SYSTEM/
    ${CMAKE_SOURCE_DIR}/src/lib/system/cpu.asm
    ${CMAKE_SOURCE_DIR}/src/lib/system/fastcpyf.asm
    ${CMAKE_SOURCE_DIR}/src/lib/system/lz.asm
    ${CMAKE_SOURCE_DIR}/src/lib/system/mousedat.asm
)

# ── Assemble each ASM file into an object using the same approach as
#    asm_test_helpers.cmake: patch SMALL→FLAT, then assemble with UASM ────

set(ASM_LIB_OBJECTS "")

# Split CMAKE_ASM_MASM_FLAGS into a proper list
separate_arguments(_uasm_flags NATIVE_COMMAND "${CMAKE_ASM_MASM_FLAGS}")

foreach(_asm_file ${LIB386_ASM_FILES})
    get_filename_component(_asm_name ${_asm_file} NAME_WE)
    get_filename_component(_asm_dir ${_asm_file} DIRECTORY)

    # Make unique output names by including subdirectory
    file(RELATIVE_PATH _asm_rel ${LIB386_DIR} ${_asm_file})
    string(REPLACE "/" "_" _asm_prefix "${_asm_rel}")
    string(REPLACE ".ASM" "" _asm_prefix "${_asm_prefix}")

    set(_patched "${CMAKE_CURRENT_BINARY_DIR}/${_asm_prefix}_flat.ASM")
    set(_obj     "${CMAKE_CURRENT_BINARY_DIR}/${_asm_prefix}.asm.o")

    # Patch .model SMALL → .model FLAT
    add_custom_command(
        OUTPUT ${_patched}
        COMMAND ${CMAKE_COMMAND}
                -DSRC=${_asm_file}
                -DDST=${_patched}
                -P ${CMAKE_SOURCE_DIR}/tests/cmake/patch_asm_flat.cmake
        DEPENDS ${_asm_file}
                ${CMAKE_SOURCE_DIR}/tests/cmake/patch_asm_flat.cmake
        COMMENT "Patching ${_asm_prefix}: .model SMALL → FLAT"
        VERBATIM
    )

    # Assemble with UASM
    add_custom_command(
        OUTPUT ${_obj}
        COMMAND ${CMAKE_ASM_MASM_COMPILER}
                ${_uasm_flags}
                -I${CMAKE_SOURCE_DIR}/src/lib/include
                -I${_asm_dir}
                -Fo${_obj}
                ${_patched}
        DEPENDS ${_patched}
        COMMENT "Assembling ${_asm_prefix}"
        VERBATIM
    )

    list(APPEND ASM_LIB_OBJECTS ${_obj})
endforeach()

# ── Build libasm_lib386.a static library from all ASM objects ───────────────

# Create a custom target that depends on all ASM objects
add_custom_target(asm_lib386_objects DEPENDS ${ASM_LIB_OBJECTS})

# Manually create the static library using ar
set(ASM_LIB386 "${CMAKE_CURRENT_BINARY_DIR}/libasm_lib386.a")
add_custom_command(
    OUTPUT ${ASM_LIB386}
    COMMAND ${CMAKE_AR} rcs ${ASM_LIB386} ${ASM_LIB_OBJECTS}
    DEPENDS ${ASM_LIB_OBJECTS}
    COMMENT "Creating libasm_lib386.a from all ASM objects"
    VERBATIM
)
add_custom_target(asm_lib386 ALL DEPENDS ${ASM_LIB386})

# ── Build selectively-renamed ASM library for polyrec ASM replay ────────────
# Rename specific function symbols that conflict with wrapper overrides.
# Globals (Log, PtrZBuffer, TabOffLine, etc.) keep their original names
# so both ASM and CPP code reference the same global data.
set(POLYREC_ASM_RENAME_SYMS
    Fill_Sphere
    Line_A
)
set(POLYREC_ASM_RENAME_FLAGS "")
foreach(_sym ${POLYREC_ASM_RENAME_SYMS})
    list(APPEND POLYREC_ASM_RENAME_FLAGS "--redefine-sym" "${_sym}=asm_${_sym}")
endforeach()

set(POLYREC_ASM_OBJECTS "")
foreach(_obj ${ASM_LIB_OBJECTS})
    get_filename_component(_obj_name ${_obj} NAME_WE)
    set(_obj_renamed "${CMAKE_CURRENT_BINARY_DIR}/${_obj_name}.polyrec_asm.o")
    add_custom_command(
        OUTPUT ${_obj_renamed}
        COMMAND ${OBJCOPY_EXECUTABLE} ${POLYREC_ASM_RENAME_FLAGS}
                ${_obj} ${_obj_renamed}
        DEPENDS ${_obj}
        COMMENT "Renaming polyrec ASM symbols in ${_obj_name}"
        VERBATIM
    )
    list(APPEND POLYREC_ASM_OBJECTS ${_obj_renamed})
endforeach()

set(POLYREC_ASM_LIB386 "${CMAKE_CURRENT_BINARY_DIR}/libpolyrec_asm_lib386.a")
add_custom_command(
    OUTPUT ${POLYREC_ASM_LIB386}
    COMMAND ${CMAKE_AR} rcs ${POLYREC_ASM_LIB386} ${POLYREC_ASM_OBJECTS}
    DEPENDS ${POLYREC_ASM_OBJECTS}
    COMMENT "Creating libpolyrec_asm_lib386.a"
    VERBATIM
)
add_custom_target(polyrec_asm_lib386 ALL DEPENDS ${POLYREC_ASM_LIB386})

# ── Shared replay includes ──────────────────────────────────────────────────
set(REPLAY_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/lib/include
    ${CMAKE_SOURCE_DIR}/tests
)

# ─────────────────────────────────────────────────────────────────────────────
# POLYGON RECORDING REPLAY
#
# Two replay programs for .lba2polyrec files:
#   - replay_polyrec_asm  (links ASM library for ASM polygon rendering)
#   - replay_polyrec_cpp  (links CPP polygon rendering libraries)
# ─────────────────────────────────────────────────────────────────────────────

set(POLYREC_REPLAY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/polyrec_replay.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/replay_polyrec_main.cpp
    ${CMAKE_SOURCE_DIR}/src/lib/snapshot/poly_recording.cpp
)

# replay_polyrec_cpp — links CPP implementations
add_executable(replay_polyrec_cpp ${POLYREC_REPLAY_SOURCES})
target_include_directories(replay_polyrec_cpp PRIVATE ${REPLAY_INCLUDES})
target_link_libraries(replay_polyrec_cpp PRIVATE
    poly svg sys snapshot m
)
target_compile_definitions(replay_polyrec_cpp PRIVATE
    "TEST_SOURCE_ROOT=\"${CMAKE_SOURCE_DIR}/\""
    ENABLE_LIB386_DEBUG_TRACES
)
set_target_properties(replay_polyrec_cpp PROPERTIES
    POSITION_INDEPENDENT_CODE OFF
)
target_link_options(replay_polyrec_cpp PRIVATE -no-pie)

# replay_polyrec_asm — links selectively-renamed ASM library + ABI wrappers
# The ASM library has Fill_Sphere/Line_A etc. renamed to asm_Fill_Sphere/asm_Line_A
# to avoid conflicts with the wrapper overrides. All other symbols (globals,
# Fill_PolyFast, Switch_Fillers_ASM) keep their original names.
add_executable(replay_polyrec_asm ${POLYREC_REPLAY_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/polyrec_asm_wrappers.cpp
)
target_include_directories(replay_polyrec_asm PRIVATE ${REPLAY_INCLUDES})
target_link_libraries(replay_polyrec_asm PRIVATE
    ${POLYREC_ASM_LIB386} poly svg sys snapshot m
)
add_dependencies(replay_polyrec_asm polyrec_asm_lib386)
target_compile_definitions(replay_polyrec_asm PRIVATE
    "TEST_SOURCE_ROOT=\"${CMAKE_SOURCE_DIR}/\""
    ENABLE_LIB386_DEBUG_TRACES
)
set_target_properties(replay_polyrec_asm PROPERTIES
    POSITION_INDEPENDENT_CODE OFF
)
target_link_options(replay_polyrec_asm PRIVATE -no-pie -Wl,--allow-multiple-definition)

# Register polyrec comparison tests for each fixture
set(COMPARE_POLYREC_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/compare_polyrec.sh")

file(GLOB POLYREC_FIXTURES "${CMAKE_CURRENT_SOURCE_DIR}/fixtures/*.lba2polyrec")
message(STATUS "POLYREC: Found ${CMAKE_CURRENT_SOURCE_DIR}/fixtures/*.lba2polyrec -> ${POLYREC_FIXTURES}")
foreach(_fixture ${POLYREC_FIXTURES})
    get_filename_component(_fixture_name ${_fixture} NAME_WE)
    add_test(
        NAME test_polyrec_${_fixture_name}
        COMMAND bash ${COMPARE_POLYREC_SCRIPT}
                ${_fixture}
                $<TARGET_FILE:replay_polyrec_asm>
                $<TARGET_FILE:replay_polyrec_cpp>
    )
endforeach()
