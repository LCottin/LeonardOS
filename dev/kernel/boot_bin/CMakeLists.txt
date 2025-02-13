# Set the output directory of the executable
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BOOT_NAME})

# Linker script file path
SET(BOOT_LINKER_SCRIPT ${BOOT_BIN_DIR}/boot_linker.ld)

# Set the name of the executable
SET(BOOT_NAME_ELF      ${BOOT_NAME}.elf)
SET(BOOT_NAME_BIN      ${BOOT_NAME}.bin)
SET(BOOT_NAME_MAP      ${BOOT_NAME}.map)
SET(BOOT_NAME_STRIPPED ${BOOT_NAME}.elf.stripped)

# Specify the source file
set(BOOT_SOURCES
    ${BOOT_DIR}/src/boot_main.S
    ${BOOT_DIR}/src/boot_data.S
    ${BOOT_DIR}/src/boot_parse_memory.S
    ${BOOT_DIR}/src/boot_print.S
    ${BOOT_DIR}/src/boot_print_addr.S
    ${KERNEL_DIR}/BMT/src/BMT_print_table.c
    ${KERNEL_DIR}/BMT/src/BMT_init.c
    ${KERNEL_DIR}/BMT/src/BMT_add_elf.c
    ${KERNEL_DIR}/BMT/src/BMT_build_table.c
    ${KERNEL_DIR}/BMT/src/BMT_get_kernel_entry.c
    ${KERNEL_DIR}/BMT/src/BMT_data.c
    ${KERNEL_DIR}/BMT/src/BMT_copy_binaries.c
    ${KERNEL_DIR}/ELF/src/ELF.c
)

set(BOOT_HEADERS
    ${KERNEL_DIR}/BMT/include/BMT.h
    ${KERNEL_DIR}/ELF/include/ELF.h
)

# Specify the public header directory
set(BOOT_INCLUDE
    ${KERNEL_DIR}/BMT/include
    ${KERNEL_DIR}/types/include
    ${KERNEL_DIR}/ELF/include
)

# Specify the private header directory
set(BOOT_INCLUDE_PRV
    ${BOOT_DIR}/src
    ${KERNEL_DIR}/BMT/src
    ${KERNEL_DIR}/ELF/src
)

# Add an executable target
add_executable(${BOOT_NAME_ELF} ${BOOT_SOURCES})

# Link header files
target_include_directories(${BOOT_NAME_ELF}
    PUBLIC ${BOOT_INCLUDE}
    PRIVATE ${BOOT_INCLUDE_PRV}
)

# Ensure the executable is built after the library
add_dependencies(${BOOT_NAME_ELF} ${LIB_MEMORY_NAME})
add_dependencies(${BOOT_NAME_ELF} ${LIB_STRING_NAME})

# Link the common library
target_link_libraries(${BOOT_NAME_ELF} -Wl,--whole-archive ${LIB_MEMORY_NAME} ${LIB_STRING_NAME})

# Set custom linker options, including the generation of the .map file
target_link_options(${BOOT_NAME_ELF} PRIVATE
                    "-T${BOOT_LINKER_SCRIPT}"
                    "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BOOT_NAME_MAP}")

# Generate .bin, .elf.stripped and .map files
add_custom_command(
    TARGET ${BOOT_NAME_ELF}
    POST_BUILD

    # Generate .elf.stripped file
    COMMAND ${CMAKE_OBJCOPY} --strip-all $<TARGET_FILE:${BOOT_NAME_ELF}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BOOT_NAME_STRIPPED}

    # Generate .bin file
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${BOOT_NAME_ELF}> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BOOT_NAME_BIN}
)
