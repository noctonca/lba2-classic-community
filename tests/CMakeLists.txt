cmake_minimum_required(VERSION 3.23)

enable_testing()

# Aggregate target + label for host-only tests (no Docker, no retail data;
# run on Linux/macOS/Windows in CI). Each test registers itself via
# register_host_test(<target>) — adding a new host test is then two lines in
# its own CMakeLists.txt, with no workflow edits required.
#
#   cmake --build build --target host_tests   # builds every registered test
#   ctest -L host_quick --output-on-failure   # runs every registered test
add_custom_target(host_tests)

function(register_host_test test_name)
    add_dependencies(host_tests ${test_name})
    set_tests_properties(${test_name} PROPERTIES LABELS host_quick)
endfunction()

add_subdirectory(discovery)
add_subdirectory(console)
add_subdirectory(credits)
add_subdirectory(copymask_negx)
add_subdirectory(version)
add_subdirectory(savegame)

if(LBA2_BUILD_ASM_EQUIV_TESTS)
include(cmake/asm_test_helpers.cmake)

add_asm_cpp_test(
	NAME test_grille
	TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test_grille.cpp
	ASM_SOURCE ${CMAKE_SOURCE_DIR}/src/engine/grille_a.asm
	RENAME_SYMS DecompColonne Map2Screen GetAdrBlock WorldColBrickFull WorldCodeBrick GetBlockBrick GetWorldColBrickVisible WorldColBrick CodeJeu XMap YMap ZMap XScreen YScreen BufCube BufMap TabBlock BufferBrick
	INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine
	LIBS 3dext 3D ail ani fio obj poly svg sys SDL3::SDL3
)
target_sources(test_grille PRIVATE ${CMAKE_SOURCE_DIR}/src/engine/grille.cpp)

add_asm_cpp_test(
	NAME test_plasma
	TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test_plasma.cpp
	ASM_SOURCE ${CMAKE_SOURCE_DIR}/src/engine/plasma.asm
	RENAME_SYMS Do_Plasma Nb_Pts_Inter Nb_Pts_Control
	INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine
)
target_sources(test_plasma PRIVATE ${CMAKE_SOURCE_DIR}/src/engine/plasma.cpp)

add_asm_cpp_test(
	NAME test_func
	TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test_func.cpp
	ASM_SOURCE ${CMAKE_SOURCE_DIR}/src/engine/func.asm
	RENAME_SYMS SearchBoundColRGB
	INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine
)
target_sources(test_func PRIVATE ${CMAKE_SOURCE_DIR}/src/engine/func.cpp)

add_asm_cpp_test(
	NAME test_flow_a
	TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test_flow_a.cpp
	ASM_SOURCE ${CMAKE_SOURCE_DIR}/src/engine/flow_a.asm
	RENAME_SYMS BoxFlow ShadeBoxBlk CopyBlockShade
	INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine
)
target_sources(test_flow_a PRIVATE ${CMAKE_SOURCE_DIR}/src/engine/flow_a.cpp)

add_asm_cpp_test(
	NAME test_fire
	TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test_fire.cpp
	ASM_SOURCE ${CMAKE_SOURCE_DIR}/src/engine/fire.asm
	RENAME_SYMS Do_Fire
	INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine
)
target_sources(test_fire PRIVATE ${CMAKE_SOURCE_DIR}/src/engine/fire.cpp)
target_sources(test_fire PRIVATE ${CMAKE_SOURCE_DIR}/src/lib/system/utils.cpp)

add_asm_cpp_test(
	NAME test_compress
	TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/test_compress.cpp
	ASM_SOURCE ${CMAKE_SOURCE_DIR}/src/engine/compress.asm
	RENAME_SYMS AddString DeleteString
	INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine
)
target_sources(test_compress PRIVATE ${CMAKE_SOURCE_DIR}/src/engine/lzss.cpp)

add_subdirectory(3d)
add_subdirectory(3dext)
add_subdirectory(system)
add_subdirectory(menu)
add_subdirectory(anim)
add_subdirectory(svga)
add_subdirectory(pol_work)
add_subdirectory(object)
add_subdirectory(snapshot)
add_subdirectory(fpu_precision)
add_subdirectory(video_audio)

endif()
