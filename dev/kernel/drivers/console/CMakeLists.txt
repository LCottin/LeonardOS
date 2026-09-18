# ==============================================================================
# Set the driver name
# ==============================================================================
set(DRV_PATH ${DRV_PATH})
set(DRV_NAME ${DRV_NAME})

# ==============================================================================
# Create source and header for IRQ
# ==============================================================================
set(CONSOLE_IRQ_DIR
    ${DRV_PATH}/code/irq
)

set(CONSOLE_IRQ_SOURCES
    # Add the path to each source file here
    ${CONSOLE_IRQ_DIR}/src/console_irq_rx.c
)

set(CONSOLE_IRQ_HEADERS
    ${CONSOLE_IRQ_DIR}/inc
)

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(CONSOLE_CTX_DIR
    ${DRV_PATH}/code/ctx
)

set(CONSOLE_CTX_SOURCES
    # Add the path to each source file here
    ${CONSOLE_CTX_DIR}/src/console_ctx_data.c
    ${CONSOLE_CTX_DIR}/src/console_ctx_init.c
)

set(CONSOLE_CTX_HEADERS
    ${CONSOLE_CTX_DIR}/inc
)

# ==============================================================================
# Create source and header for BUFFER
# ==============================================================================
set(CONSOLE_BUFFER_DIR
    ${DRV_PATH}/code/buffer
)

set(CONSOLE_BUFFER_SOURCES
    # Add the path to each source file here
    ${CONSOLE_BUFFER_DIR}/src/console_buffer_is_empty.c
    ${CONSOLE_BUFFER_DIR}/src/console_buffer_pop.c
    ${CONSOLE_BUFFER_DIR}/src/console_buffer_push.c
)

set(CONSOLE_BUFFER_HEADERS
    ${CONSOLE_BUFFER_DIR}/inc
)

# ==============================================================================
# Create library target for CONSOLE
# ==============================================================================
add_library(${DRV_NAME}
    STATIC
        # Add the path to each source directory here
        ${CONSOLE_BUFFER_SOURCES}
        ${CONSOLE_CTX_SOURCES}
        ${CONSOLE_IRQ_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${DRV_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${CONSOLE_BUFFER_HEADERS}
        ${CONSOLE_CTX_HEADERS}
        ${CONSOLE_IRQ_HEADERS}
    PUBLIC
        ${DRV_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${DRV_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        libraries.lib_containers
        drivers.lib_uart
        arch.lib_irq
)
