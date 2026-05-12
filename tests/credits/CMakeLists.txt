add_executable(test_credits_parse
    test_credits_parse.cpp
    ${CMAKE_SOURCE_DIR}/src/engine/credits_parse.cpp
)

target_include_directories(test_credits_parse PRIVATE
    ${CMAKE_SOURCE_DIR}/src/engine
    ${CMAKE_SOURCE_DIR}/src/lib/include
)

set_target_properties(test_credits_parse PROPERTIES CXX_STANDARD 11)

add_test(NAME test_credits_parse COMMAND test_credits_parse)

register_host_test(test_credits_parse)
