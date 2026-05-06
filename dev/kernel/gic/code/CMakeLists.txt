# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for SGI
# ==============================================================================
set(GIC_SGI_DIR
    ${COMPONENT_NAME}/code/sgi
)

set(GIC_SGI_SOURCES
    # Add the path to each source file here
    ${GIC_SGI_DIR}/src/gic_sgi_send.c
)

set(GIC_SGI_HEADERS
    ${GIC_SGI_DIR}/inc
)

# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(GIC_INIT_DIR
    ${COMPONENT_NAME}/code/init
)

set(GIC_INIT_SOURCES
    # Add the path to each source file here
    ${GIC_INIT_DIR}/src/gic_init_irq.c
    ${GIC_INIT_DIR}/src/gic_init.c
)

set(GIC_INIT_HEADERS
    ${GIC_INIT_DIR}/inc
)

# ==============================================================================
# Create source and header for DIST
# ==============================================================================
set(GIC_DIST_DIR
    ${COMPONENT_NAME}/code/dist
)

set(GIC_DIST_SOURCES
# Add the path to each source file here
    ${GIC_DIST_DIR}/src/gic_dist_enable_irq.c
    ${GIC_DIST_DIR}/src/gic_dist_route_to_cpu.c
)

set(GIC_DIST_HEADERS
    ${GIC_DIST_DIR}/inc
)

# ==============================================================================
# Create source and header for CPU
# ==============================================================================
set(GIC_CPU_DIR
    ${COMPONENT_NAME}/code/cpu
)

set(GIC_CPU_SOURCES
    # Add the path to each source file here
    ${GIC_CPU_DIR}/src/gic_cpu_ack.c
    ${GIC_CPU_DIR}/src/gic_cpu_eoi.c
    ${GIC_CPU_DIR}/src/gic_cpu_set_priority.c
)

set(GIC_CPU_HEADERS
    ${GIC_CPU_DIR}/inc
)

# ==============================================================================
# Create library kernel target for GIC
# ==============================================================================
set(LIB_NAME_KRN ${GIC_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source directory here
        ${GIC_SGI_SOURCES}
        ${GIC_CPU_SOURCES}
        ${GIC_DIST_SOURCES}
        ${GIC_INIT_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${GIC_SGI_HEADERS}
        ${GIC_CPU_HEADERS}
        ${GIC_DIST_HEADERS}
        ${GIC_INIT_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${MMIO_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
