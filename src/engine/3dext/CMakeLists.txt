# General sources
set(SOURCES_FILES decors.cpp globext.cpp lba_ext.cpp loadisle.cpp maptools.cpp terrain.cpp)
# set(SOURCES_FILES_ASM boxzbuf.asm linerain.asm)
set(SOURCES_FILES_ASM boxzbuf.cpp linerain.cpp)

add_library(3dext ${SOURCES_FILES} ${SOURCES_FILES_ASM})
target_compile_definitions(3dext PRIVATE ONE_GAME_DIRECTORY LBA_GAME CDROM)
target_link_libraries(3dext PUBLIC sys svg 3D obj poly ani fio)
target_include_directories(3dext PUBLIC ${CMAKE_SOURCE_DIR}/src/lib/include)

# Configure all ASM files to be recognized as such (workaround for bug where .ASM uppercase extension is not recognized)
# foreach (FILE_ASM IN LISTS SOURCES_FILES_ASM)
#     set_source_files_properties(${FILE_ASM} PROPERTIES LANGUAGE ASM_MASM)
# endforeach ()

# Source files in folder but not used on CMakeScript:
# - drawsky.cpp (but used as included on source file "terrain.cpp")
# - var_ext.cpp (but used as included on source file "globext.cpp")
