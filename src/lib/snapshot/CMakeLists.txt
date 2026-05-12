add_library(snapshot poly_recording.cpp)
target_include_directories(snapshot PRIVATE ${CMAKE_SOURCE_DIR}/src/lib/include)
