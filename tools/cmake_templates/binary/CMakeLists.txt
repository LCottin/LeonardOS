# ==============================================================================
# Set the output directory of the executable
# ==============================================================================
set(BIN_NAME "bin_name")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME})

# ==============================================================================
# Linker script file path
# ==============================================================================
set(LINKER_SCRIPT linker.ld)

# ==============================================================================
# Create executable target
# ==============================================================================
add_executable(${BIN_NAME}.elf
    # Add other source files here
)

# ==============================================================================
# Link with the component libraries
# ==============================================================================
target_link_libraries(${BIN_NAME}.elf -Wl
    PRIVATE
        # Add component libraries here
        component_impl
)

# ==============================================================================
# Set custom linker options, including the generation of the .map file
# ==============================================================================
target_link_options(${BIN_NAME}.elf
    PRIVATE
        "-T${LINKER_SCRIPT}"
        "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.map"
)

# ==============================================================================
# Generate .bin, .elf.stripped and .map files
# ==============================================================================
add_custom_command(
    TARGET
    ${BIN_NAME}.elf
    POST_BUILD

    # Generate .elf.stripped file
    COMMAND ${CMAKE_OBJCOPY} --strip-all $<TARGET_FILE:${BIN_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.elf.stripped

    # Generate .bin file
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${BIN_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BIN_NAME}.bin
)
