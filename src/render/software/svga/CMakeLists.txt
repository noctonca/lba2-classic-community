# General sources
set(SOURCES_FILES clip.cpp dirtybox.cpp gprintf.cpp graph.cpp initmode.cpp plot.cpp rect.cpp screen.cpp
        screenxy.cpp sdl.cpp)

# set(SOURCES_FILES_ASM affstr.asm blitboxf.asm box.asm calcmask.asm clip.asm clrboxf.asm copymask.asm
#         cpybloci.asm cpyblock.asm font.asm graph.asm mask.asm resblock.asm savblock.asm scalebox.asm scalespi.asm
#         scalespt.asm)
set(SOURCES_FILES_ASM affstr.cpp blitboxf.cpp box.cpp calcmask.cpp clip.cpp clrboxf.cpp copymask.cpp
        cpybloci.cpp cpyblock.cpp font.cpp graph.cpp mask.cpp resblock.cpp savblock.cpp scalebox.cpp scalespi.cpp
        scalespt.cpp)

add_library(svg ${SOURCES_FILES} ${SOURCES_FILES_ASM})
target_link_libraries(svg PUBLIC sys ${LBA2_SDL3_TARGET})
target_compile_definitions(svg PRIVATE SDL_DISABLE_OLD_NAMES)

# Configure all ASM files to be recognized as such (workaround for bug where .ASM uppercase extension is not recognized)
# foreach (FILE_ASM IN LISTS SOURCES_FILES_ASM)
#   set_source_files_properties(${FILE_ASM} PROPERTIES LANGUAGE ASM_MASM)
# endforeach ()
