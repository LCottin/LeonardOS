# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(MMU_INIT_DIR
    ${COMPONENT_NAME}/code/init
)

set(MMU_INIT_SOURCES
    # Add the path to each source file here
    ${MMU_INIT_DIR}/src/mmu_init.S
)

set(MMU_INIT_HEADERS
    ${MMU_INIT_DIR}/inc
)

# ==============================================================================
# Create source and header for MAP
# ==============================================================================
set(MMU_MAP_DIR
    ${COMPONENT_NAME}/code/map
)

set(MMU_MAP_SOURCES
    # Add the path to each source file here
    ${MMU_MAP_DIR}/src/mmu_map_all.c
    ${MMU_MAP_DIR}/src/mmu_map_binary.c
    ${MMU_MAP_DIR}/src/mmu_map_boot.c
    ${MMU_MAP_DIR}/src/mmu_map_data.c
    ${MMU_MAP_DIR}/src/mmu_map_get_alloc_table.c
    ${MMU_MAP_DIR}/src/mmu_map_init_kernel_l0.c
    ${MMU_MAP_DIR}/src/mmu_map_get_kernel_l0.c
    ${MMU_MAP_DIR}/src/mmu_map_page.c
    ${MMU_MAP_DIR}/src/mmu_map_region.c
)

set(MMU_MAP_HEADERS
    ${MMU_MAP_DIR}/inc
)

# ==============================================================================
# Create source and header for PAGE
# ==============================================================================
set(MMU_PAGE_DIR
    ${COMPONENT_NAME}/code/page
)

set(MMU_PAGE_SOURCES
    # Add the path to each source file here
    ${MMU_PAGE_DIR}/src/mmu_page_alloc.c
    ${MMU_PAGE_DIR}/src/mmu_page_data.c
    ${MMU_PAGE_DIR}/src/mmu_page_init.c
)

set(MMU_PAGE_HEADERS
    ${MMU_PAGE_DIR}/inc
)

# ==============================================================================
# Create library kernel target for MMU
# ==============================================================================
set(LIB_NAME_KRN ${MMU_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${MMU_INIT_SOURCES}
        ${MMU_MAP_SOURCES}
        ${MMU_PAGE_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${MMU_INIT_HEADERS}
        ${MMU_MAP_HEADERS}
        ${MMU_PAGE_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${BMT_LIB_NAME}_krn
        ${ELF_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
