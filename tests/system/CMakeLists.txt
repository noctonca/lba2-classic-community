set(_SYS_ASM_DIR ${CMAKE_SOURCE_DIR}/src/lib/system)
set(_SYS_ASM_INC ${CMAKE_SOURCE_DIR}/src/lib/include)

add_asm_cpp_test(
    NAME test_lz  TEST_SOURCE test_lz.cpp
    ASM_SOURCE ${_SYS_ASM_DIR}/lz.asm
    RENAME_SYMS ExpandLZ
    LIBS sys
    ASM_INCLUDE_DIRS ${_SYS_ASM_INC}
)

# .model SMALL ASM files are automatically patched to FLAT at build time.
add_asm_cpp_test(
    NAME test_fastcpyf  TEST_SOURCE test_fastcpyf.cpp
    ASM_SOURCE ${_SYS_ASM_DIR}/fastcpyf.asm
    RENAME_SYMS FastCopy FastCopyF
    LIBS sys
    ASM_INCLUDE_DIRS ${_SYS_ASM_INC}
)

add_asm_cpp_test(
    NAME test_cpu  TEST_SOURCE test_cpu.cpp
    ASM_SOURCE ${_SYS_ASM_DIR}/cpu.asm
    RENAME_SYMS ProcessorManufacturerIDString
                ProcessorSignature ProcessorFeatureFlags
                Processor4KBDataTLB Processor4KBInstructionTLB
                Processor4MBDataTLB Processor4MBInstructionTLB
                ProcessorL1DataCache ProcessorL1InstructionCache
                ProcessorL2Cache
    LIBS sys
    ASM_INCLUDE_DIRS ${_SYS_ASM_INC}
)

add_asm_cpp_test(
    NAME test_mousedat  TEST_SOURCE test_mousedat.cpp
    ASM_SOURCE ${_SYS_ASM_DIR}/mousedat.asm
    RENAME_SYMS BinGphMouse
    LIBS sys
    ASM_INCLUDE_DIRS ${_SYS_ASM_INC}
)
