include_directories(include)

# Enable debug traces for ASM-vs-CPP comparison when building tests
if(LBA2_BUILD_TESTS)
  add_definitions(-DENABLE_LIB386_DEBUG_TRACES)
endif()

add_subdirectory(math)
add_subdirectory(audio)
add_subdirectory(anim)
add_subdirectory(fileio)
add_subdirectory(object)
add_subdirectory(system)

# render/software hosts pol_work + svga (was src/render/software/pol_work and src/render/software/svga).
# They live under src/render/software/ but their CMake targets are added here
# alongside the other libraries until the render/ tree gets its own top.
add_subdirectory(${CMAKE_SOURCE_DIR}/src/render/software/pol_work ${CMAKE_BINARY_DIR}/src/render/software/pol_work)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/render/software/svga ${CMAKE_BINARY_DIR}/src/render/software/svga)

if(ENABLE_POLY_RECORDING OR LBA2_BUILD_TESTS)
  add_subdirectory(snapshot)
endif()

if(MVIDEO_BACKEND STREQUAL "smacker")
  add_subdirectory(third_party/libsmacker)
endif()

if(MVIDEO_BACKEND STREQUAL "smacker" OR LBA2_BUILD_TESTS)
  add_subdirectory(audio_resample)
endif()
