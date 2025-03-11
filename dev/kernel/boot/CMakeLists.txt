# ==============================================================================
# Create source and header for PRINT
# ==============================================================================
set(BOOT_PRINT_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/print
)

set(BOOT_PRINT_SOURCES
    # Add the path to each source file here
    ${BOOT_PRINT_DIR}/src/boot_print_addr.S
    ${BOOT_PRINT_DIR}/src/boot_print_msg.S
)

set (BOOT_PRINT_HEADERS
    ${BOOT_PRINT_DIR}/include
)

# ==============================================================================
# Create source and header for MEMORY
# ==============================================================================
set(BOOT_MEMORY_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/memory
)

set(BOOT_MEMORY_SOURCES
    # Add the path to each source file here
    ${BOOT_MEMORY_DIR}/src/boot_memory_parse.S
)

set (BOOT_MEMORY_HEADERS
    ${BOOT_MEMORY_DIR}/include
)

# ==============================================================================
# Create source and header for MAIN
# ==============================================================================
set(BOOT_MAIN_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/main
)

set(BOOT_MAIN_SOURCES
    # Add the path to each source file here
    ${BOOT_MAIN_DIR}/src/boot_main.S
)

set (BOOT_MAIN_HEADERS
    ${BOOT_MAIN_DIR}/include
)

# ==============================================================================
# Create library target for BOOT
# ==============================================================================
set (LIB_NAME ${BOOT_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${BOOT_PRINT_SOURCES}
        ${BOOT_MEMORY_SOURCES}
        ${BOOT_MAIN_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${BOOT_PRINT_HEADERS}
        ${BOOT_MEMORY_HEADERS}
        ${BOOT_MAIN_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}
        ${BMT_LIB_NAME}
    "-Wl,--no-whole-archive"
)
