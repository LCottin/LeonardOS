# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(BMT_CTX_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/ctx
)

set(BMT_CTX_SOURCES
    # Add the path to each source file here
    ${BMT_CTX_DIR}/src/bmt_ctx_data.c
    ${BMT_CTX_DIR}/src/bmt_ctx_init.c
)

set (BMT_CTX_HEADERS
    ${BMT_CTX_DIR}/include
)

# ==============================================================================
# Create source and header for BUILD
# ==============================================================================
set(BMT_BUILD_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/build
)

set(BMT_BUILD_SOURCES
    # Add the path to each source file here
    ${BMT_BUILD_DIR}/src/bmt_build_add_elf.c
    ${BMT_BUILD_DIR}/src/bmt_build_copy_binaries.c
    ${BMT_BUILD_DIR}/src/bmt_build_table.c
)

set (BMT_BUILD_HEADERS
    ${BMT_BUILD_DIR}/include
)

# ==============================================================================
# Create source and header for INFO
# ==============================================================================
set(BMT_INFO_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/info
)

set(BMT_INFO_SOURCES
    # Add the path to each source file here
    ${BMT_INFO_DIR}/src/bmt_info_get_kernel_entry.c
    ${BMT_INFO_DIR}/src/bmt_info_get_kernel_stack_top.c
    ${BMT_INFO_DIR}/src/bmt_info_print_table.c
)

set (BMT_INFO_HEADERS
    ${BMT_INFO_DIR}/include
)

# ==============================================================================
# Create library target for BMT
# ==============================================================================
set (LIB_NAME ${BMT_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${BMT_CTX_SOURCES}
        ${BMT_BUILD_SOURCES}
        ${BMT_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${BMT_CTX_HEADERS}
        ${BMT_BUILD_HEADERS}
        ${BMT_INFO_HEADERS}
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
        ${ELF_LIB_NAME}
        ${MEMORY_OPS_LIB_NAME}
        ${SERIAL_LIB_NAME}
        ${STRINGS_LIB_NAME}
    "-Wl,--no-whole-archive"
)
