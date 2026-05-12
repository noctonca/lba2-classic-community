# General sources
set(SOURCES_FILES availmem.cpp cmdline.cpp deffile.cpp dispos.cpp events.cpp exit.cpp
        filecopy.cpp filename.cpp files.cpp hqfile.cpp hqmem.cpp hqrload.cpp hqrmem.cpp hqrmload.cpp hqrress.cpp
        input.cpp itoa.cpp keyboard.cpp loadmall.cpp loadsave.cpp logprint.cpp mouse.cpp n_malloc.cpp
        s_malloc.cpp string.cpp system.cpp timer.cpp window.cpp utils.cpp)

# set(SOURCES_FILES_ASM cpu.asm fastcpyf.asm lz.asm mousedat.asm)
set(SOURCES_FILES_ASM cpu.cpp fastcpyf.cpp lz.cpp mousedat.cpp)

add_library(sys ${SOURCES_FILES} ${SOURCES_FILES_ASM})
target_link_libraries(sys svg)

# Configure all ASM files to be recognized as such (workaround for bug where .ASM uppercase extension is not recognized)
# foreach (FILE_ASM IN LISTS SOURCES_FILES_ASM)
#     set_source_files_properties(${FILE_ASM} PROPERTIES LANGUAGE ASM_MASM)
# endforeach ()
