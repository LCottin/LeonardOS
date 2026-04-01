# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(BMT_CTX_DIR
    ${COMPONENT_NAME}/code/ctx
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
    ${COMPONENT_NAME}/code/build
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
    ${COMPONENT_NAME}/code/info
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
# Create library kernel target for BMT
# ==============================================================================
set(LIB_NAME_KRN ${BMT_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${BMT_CTX_SOURCES}
        ${BMT_BUILD_SOURCES}
        ${BMT_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${BMT_CTX_HEADERS}
        ${BMT_BUILD_HEADERS}
        ${BMT_INFO_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${ELF_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
        ${PRINTER_LIB_NAME}_krn
        ${STRINGS_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
