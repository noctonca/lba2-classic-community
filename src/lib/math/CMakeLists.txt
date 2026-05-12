# General sources
set(SOURCES_FILES camera.cpp datamat.cpp distance.cpp imatstd.cpp light.cpp lirot3d.cpp lproj.cpp lrot3d.cpp move.cpp
        rot3d.cpp)

# set(SOURCES_FILES_ASM copymatf.asm getang2d.asm getang3d.asm imatstdf.asm imattraf.asm light.asm lirot3df.asm
#         litlistf.asm lproj3df.asm lprojiso.asm lrot2df.asm lrot3df.asm mulmatf.asm prli3df.asm prliiso.asm proj.asm
#         regle3.asm rotmatu.asm rotralif.asm rotvect.asm sintab.asm sintabf.asm sqrroot.asm tantab.asm)
set(SOURCES_FILES_ASM copymatf.cpp getang2d.cpp getang3d.cpp imatstdf.cpp imattraf.cpp light.cpp lirot3df.cpp
        litlistf.cpp lproj3df.cpp lprojiso.cpp lrot2df.cpp lrot3df.cpp mulmatf.cpp prli3df.cpp prliiso.cpp proj.cpp
        regle3.cpp rotmatu.cpp rotralif.cpp rotvect.cpp sintab.cpp sintabf.cpp sqrroot.cpp tantab.cpp)

add_library(3D ${SOURCES_FILES} ${SOURCES_FILES_ASM})

# Configure all ASM files to be recognized as such (workaround for bug where .ASM uppercase extension is not recognized)
# foreach (FILE_ASM IN LISTS SOURCES_FILES_ASM)
#     set_source_files_properties(${FILE_ASM} PROPERTIES LANGUAGE ASM_MASM)
# endforeach ()
