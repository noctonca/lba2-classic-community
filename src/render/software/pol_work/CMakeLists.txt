set(SOURCES_FILES poly.cpp)

# set(SOURCES_FILES_ASM poly.asm poly_jmp.asm polyclip.asm polydisc.asm polyflat.asm polygour.asm
#         polygtex.asm polyline.asm polyline.asm polytext.asm polytext.asm polytexz.asm polytzf.asm polytzg.asm
#         testvuef.asm)
set(SOURCES_FILES_ASM poly.cpp poly_jmp.cpp polyclip.cpp polydisc.cpp polyflat.cpp polygour.cpp
        polygtex.cpp polyline.cpp polyline.cpp polytext.cpp polytext.cpp polytexz.cpp polytzf.cpp polytzg.cpp
        testvuef.cpp)

add_library(poly ${SOURCES_FILES} ${SOURCES_FILES_ASM})

# Propagate ENABLE_POLY_RECORDING to the poly library so recording hooks compile
if(ENABLE_POLY_RECORDING)
  target_compile_definitions(poly PRIVATE ENABLE_POLY_RECORDING)
endif()


# Configure all ASM files to be recognized as such (workaround for bug where .ASM uppercase extension is not recognized)
# foreach (FILE_ASM IN LISTS SOURCES_FILES_ASM)
#     set_source_files_properties(${FILE_ASM} PROPERTIES LANGUAGE ASM_MASM)
# endforeach ()
