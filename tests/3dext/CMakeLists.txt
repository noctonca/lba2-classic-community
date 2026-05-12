set(_3DEXT_ASM_DIR ${CMAKE_SOURCE_DIR}/src/engine/3dext)
set(_3DEXT_ASM_INC ${CMAKE_SOURCE_DIR}/src/lib/include)

add_asm_cpp_test(NAME test_boxzbuf
    TEST_SOURCE test_boxzbuf.cpp
    ASM_SOURCE ${_3DEXT_ASM_DIR}/boxzbuf.asm
    RENAME_SYMS ZBufBoxOverWrite2
    INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine/3dext
    ASM_INCLUDE_DIRS ${_3DEXT_ASM_INC})

target_sources(test_boxzbuf PRIVATE
    ${CMAKE_SOURCE_DIR}/src/engine/3dext/boxzbuf.cpp)

add_asm_cpp_test(NAME test_linerain
    TEST_SOURCE test_linerain.cpp
    ASM_SOURCE ${_3DEXT_ASM_DIR}/linerain.asm
    RENAME_SYMS LineRain
    INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src/engine/3dext
    ASM_INCLUDE_DIRS ${_3DEXT_ASM_INC})

target_sources(test_linerain PRIVATE
    ${CMAKE_SOURCE_DIR}/src/engine/3dext/linerain.cpp)