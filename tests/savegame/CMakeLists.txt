add_executable(test_savegame_load_bounds test_load_bounds.cpp
    ${CMAKE_SOURCE_DIR}/src/engine/savegame_load_bounds.cpp)

target_include_directories(test_savegame_load_bounds PRIVATE
    ${CMAKE_SOURCE_DIR}/src/engine
    ${CMAKE_SOURCE_DIR}/src/lib/include
)

set_target_properties(test_savegame_load_bounds PROPERTIES CXX_STANDARD 11)

add_test(NAME test_savegame_load_bounds COMMAND test_savegame_load_bounds)

register_host_test(test_savegame_load_bounds)
