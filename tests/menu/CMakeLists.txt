set(_MENU_ASM_DIR ${CMAKE_SOURCE_DIR}/src/lib/menu)
set(_MENU_ASM_INC ${CMAKE_SOURCE_DIR}/src/lib/include)

# NOTE: sort.cpp contains only commented ASM — no C implementation exists.
add_asm_cpp_test(
    NAME test_sort  TEST_SOURCE test_sort.cpp
    ASM_SOURCE ${_MENU_ASM_DIR}/sort.asm
    RENAME_SYMS MySortCompFunc
    LIBS sys
    ASM_INCLUDE_DIRS ${_MENU_ASM_INC}
)
target_sources(test_sort PRIVATE ${_MENU_ASM_DIR}/sort.cpp)
# sort.asm references strcmp_ (Watcom-mangled name for strcmp)
target_link_options(test_sort PRIVATE -Wl,--unresolved-symbols=ignore-in-object-files)
