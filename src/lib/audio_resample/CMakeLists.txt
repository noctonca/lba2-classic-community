add_library(video_audio_resample video_audio_resample.cpp)
target_include_directories(video_audio_resample PUBLIC
  ${CMAKE_SOURCE_DIR}/src/lib/include
)
