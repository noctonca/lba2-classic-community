# set(SOURCES_FILES_ASM anim.asm body.asm clear.asm frame.asm intanim.asm interdep.asm intframe.asm libinit.asm
#         stoframe.asm texture.asm)
set(SOURCES_FILES_ASM anim.cpp body.cpp clear.cpp frame.cpp intanim.cpp interdep.cpp intframe.cpp libinit.cpp
        stoframe.cpp texture.cpp)

add_library(ani ${SOURCES_FILES_ASM})

# Configure all ASM files to be recognized as such (workaround for bug where .ASM uppercase extension is not recognized)
# foreach (FILE_ASM IN LISTS SOURCES_FILES_ASM)
#     set_source_files_properties(${FILE_ASM} PROPERTIES LANGUAGE ASM_MASM)
# endforeach ()
