# add_library(obj aff_obj.asm)
add_library(obj aff_obj.cpp)
target_link_libraries(obj PRIVATE 3D)
# set_source_files_properties(aff_obj.asm PROPERTIES LANGUAGE ASM_MASM)

# Source files in folder but not used on CMakeScript:
# - 3D_OBJ.ASM
