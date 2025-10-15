# ==============================================================================
# Set the output directory of the executable
# ==============================================================================
set(APP_NAME "count_down")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DEV_DIR}/${APP_NAME})

# ==============================================================================
# Linker script file path
# ==============================================================================
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld)

# ==============================================================================
# Create source and header for PART
# ==============================================================================
set(APP_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(APP_SOURCES
    ${APP_DIR}/src/count_down.c
)

set(APP_HEADERS
    ${APP_DIR}/include/count_down.h
)

# ==============================================================================
# Create executable target
# ==============================================================================
add_executable(${APP_NAME}.elf ${APP_SOURCES})

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${APP_NAME}.elf
    PRIVATE
        # Add the path to each header directory here
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${APP_NAME}.elf
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_usr
        ${LIBUSER_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Set custom linker options, including the generation of the .map file
# ==============================================================================
target_link_options(${APP_NAME}.elf
    PRIVATE
        "-T${LINKER_SCRIPT}"
        "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APP_NAME}.map"
)

# ==============================================================================
# Generate .bin, .elf.stripped and .map files
# ==============================================================================
add_custom_command(
    TARGET
    ${APP_NAME}.elf
    POST_BUILD

    # Generate .elf.stripped file
    COMMAND ${CMAKE_OBJCOPY} --strip-all $<TARGET_FILE:${APP_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APP_NAME}.elf.stripped

    # Generate .bin file
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${APP_NAME}.elf> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APP_NAME}.bin
)

