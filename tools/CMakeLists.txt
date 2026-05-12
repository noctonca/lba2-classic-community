# Small host utilities (no SDL). Optional: set OFF for minimal configures if needed.
option(LBA2_BUILD_SAVE_TOOLS "Build save inspection helpers (save_decompress)" ON)

if(LBA2_BUILD_SAVE_TOOLS)
    add_executable(save_decompress save_decompress.cpp ${CMAKE_SOURCE_DIR}/src/lib/system/lz.cpp)
    target_include_directories(save_decompress PRIVATE ${CMAKE_SOURCE_DIR}/src/lib/include)
    # Match LIB386 C++ dialect
    set_target_properties(save_decompress PROPERTIES CXX_STANDARD 98)
endif()
