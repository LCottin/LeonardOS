# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for IRQ
# ==============================================================================
set(CONSOLE_IRQ_DIR
    ${COMPONENT_NAME}/code/irq
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
    ${COMPONENT_NAME}/code/ctx
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
    ${COMPONENT_NAME}/code/buffer
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
# Create library kernel target for CONSOLE
# ==============================================================================
set(LIB_NAME_KRN ${CONSOLE_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source directory here
        ${CONSOLE_BUFFER_SOURCES}
        ${CONSOLE_CTX_SOURCES}
        ${CONSOLE_IRQ_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${CONSOLE_BUFFER_HEADERS}
        ${CONSOLE_CTX_HEADERS}
        ${CONSOLE_IRQ_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${CONTAINERS_LIB_NAME}_krn
        ${UART_LIB_NAME}_krn
        ${IRQ_LIB_NAME}_krn
)
