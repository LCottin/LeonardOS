# Set linker script
SET(BOOT_LINKER_SCRIPT ${BOOT_BIN_DIR}/boot_linker.ld)

# Specify the source file
set(BOOT_SOURCES
    ${BOOT_DIR}/src/boot_main.s)

set(BOOT_HEADERS
)

# Specify the public header directory
set(BOOT_INCLUDE
)

# Specify the private header directory
set(BOOT_INCLUDE_PRV
)

# Add an executable target
add_executable(${BOOT_NAME} ${BOOT_SOURCES})

# Link header files
target_include_directories(${BOOT_NAME}
    PUBLIC ${BOOT_INCLUDE}
    PRIVATE ${BOOT_INCLUDE_PRV}
)

# Set custom linker options, including the generation of the .map file
target_link_options(${BOOT_NAME} PRIVATE
                    "-T${BOOT_LINKER_SCRIPT}"
                    "-Wl,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BOOT_NAME}.map")
