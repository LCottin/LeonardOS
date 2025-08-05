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

set(BOOT_MEMORY_HEADERS
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

set(BOOT_MAIN_HEADERS
    ${BOOT_MAIN_DIR}/include
)

# ==============================================================================
# Create library kernel target for BOOT
# ==============================================================================
set(LIB_NAME_KRN ${BOOT_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${BOOT_MEMORY_SOURCES}
        ${BOOT_MAIN_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${BOOT_MEMORY_HEADERS}
        ${BOOT_MAIN_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${BMT_LIB_NAME}_krn
        ${PRINTER_LIB_NAME}_krn
        ${SEH_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
