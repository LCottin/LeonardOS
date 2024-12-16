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
    ${BOOT_DIR}/src/boot_main.s
)

set(BOOT_HEADERS
    ${BOOT_DIR}/include/boot.h
)

# Specify the public header directory
set(BOOT_INCLUDE
    ${BOOT_DIR}/include
)

# Specify the private header directory
set(BOOT_INCLUDE_PRV
)

# Add an executable target
add_executable(${BOOT_NAME_ELF} ${BOOT_SOURCES})

# Link header files
target_include_directories(${BOOT_NAME_ELF}
    PUBLIC ${BOOT_INCLUDE}
    PRIVATE ${BOOT_INCLUDE_PRV}
)

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
