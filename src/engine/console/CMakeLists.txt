add_library(console console.cpp console_state.cpp)
target_include_directories(console PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  ${CMAKE_SOURCE_DIR}/src/lib/include
)
target_link_libraries(console PRIVATE SDL3::SDL3)
target_compile_definitions(console PRIVATE ONE_GAME_DIRECTORY LBA_GAME CDROM SDL_DISABLE_OLD_NAMES)
