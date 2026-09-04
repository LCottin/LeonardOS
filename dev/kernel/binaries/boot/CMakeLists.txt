# ==============================================================================
# Set the library name
# ==============================================================================
set(LIB_NAME ${LIB_NAME})
set(LIB_PATH ${LIB_PATH})

# ==============================================================================
# Create source and header for MEMORY
# ==============================================================================
set(BOOT_MEMORY_DIR
    ${LIB_PATH}/code/memory
)

set(BOOT_MEMORY_SOURCES
    # Add the path to each source file here
    ${BOOT_MEMORY_DIR}/src/boot_memory_parse.S
)

set(BOOT_MEMORY_HEADERS
    ${BOOT_MEMORY_DIR}/inc
)

# ==============================================================================
# Create source and header for MAIN
# ==============================================================================
set(BOOT_MAIN_DIR
    ${LIB_PATH}/code/main
)

set(BOOT_MAIN_SOURCES
    # Add the path to each source file here
    ${BOOT_MAIN_DIR}/src/boot_main.S
)

set(BOOT_MAIN_HEADERS
    ${BOOT_MAIN_DIR}/inc
)

# ==============================================================================
# Create library target for BOOT
# ==============================================================================
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${BOOT_MEMORY_SOURCES}
        ${BOOT_MAIN_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${BOOT_MEMORY_HEADERS}
        ${BOOT_MAIN_HEADERS}
    PUBLIC
        ${LIB_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        system.lib_bmt
        system.lib_printer
)
