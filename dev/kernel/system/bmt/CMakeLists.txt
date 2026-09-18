# ==============================================================================
# Set the system name
# ==============================================================================
set(SYS_PATH ${SYS_PATH})
set(SYS_NAME ${SYS_NAME})

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(BMT_CTX_DIR
    ${SYS_PATH}/code/ctx
)

set(BMT_CTX_SOURCES
    # Add the path to each source file here
    ${BMT_CTX_DIR}/src/bmt_ctx_data.c
    ${BMT_CTX_DIR}/src/bmt_ctx_init.c
    ${BMT_CTX_DIR}/src/bmt_ctx_init_kernel.c
)

set(BMT_CTX_HEADERS
    ${BMT_CTX_DIR}/inc
)

# ==============================================================================
# Create source and header for BUILD
# ==============================================================================
set(BMT_BUILD_DIR
    ${SYS_PATH}/code/build
)

set(BMT_BUILD_SOURCES
    # Add the path to each source file here
    ${BMT_BUILD_DIR}/src/bmt_build_add_elf.c
    ${BMT_BUILD_DIR}/src/bmt_build_add_app_elf.c
    ${BMT_BUILD_DIR}/src/bmt_build_add_krn_elf.c
    ${BMT_BUILD_DIR}/src/bmt_build_copy_binaries.c
    ${BMT_BUILD_DIR}/src/bmt_build_load_segment.c
    ${BMT_BUILD_DIR}/src/bmt_build_table.c
)

set(BMT_BUILD_HEADERS
    ${BMT_BUILD_DIR}/inc
)

# ==============================================================================
# Create source and header for INFO
# ==============================================================================
set(BMT_INFO_DIR
    ${SYS_PATH}/code/info
)

set(BMT_INFO_SOURCES
    # Add the path to each source file here
    ${BMT_INFO_DIR}/src/bmt_info_get_kernel_entry.c
    ${BMT_INFO_DIR}/src/bmt_info_get_kernel_stack_top.c
    ${BMT_INFO_DIR}/src/bmt_info_get_app_entry.c
    ${BMT_INFO_DIR}/src/bmt_info_get_app_count.c
    ${BMT_INFO_DIR}/src/bmt_info_get_app_stack_top.c
    ${BMT_INFO_DIR}/src/bmt_info_print_table.c
)

set(BMT_INFO_HEADERS
    ${BMT_INFO_DIR}/inc
)

# ==============================================================================
# Create library target for BMT
# ==============================================================================
add_library(${SYS_NAME}
    STATIC
        # Add the path to each source file here
        ${BMT_CTX_SOURCES}
        ${BMT_BUILD_SOURCES}
        ${BMT_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${SYS_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${BMT_CTX_HEADERS}
        ${BMT_BUILD_HEADERS}
        ${BMT_INFO_HEADERS}
    PUBLIC
        ${SYS_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${SYS_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        system.lib_elf
        memory.lib_tools
        system.lib_printer
        libraries.lib_strings
        libraries.lib_formatter
        libraries.lib_stream
        libraries.lib_metadata
)
