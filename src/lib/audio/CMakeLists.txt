add_library(ail)

if (${SOUND_BACKEND} STREQUAL "null")
    add_subdirectory(null)
elseif (${SOUND_BACKEND} STREQUAL "miles")
    add_subdirectory(miles)
elseif (${SOUND_BACKEND} STREQUAL "sdl")
    add_subdirectory(sdl)
endif ()
