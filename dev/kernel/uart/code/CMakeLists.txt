# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(UART_CTX_DIR
    ${COMPONENT_NAME}/code/ctx
)

set(UART_CTX_SOURCES
    # Add the path to each source file here
    ${UART_CTX_DIR}/src/uart_ctx_init.c
)

set(UART_CTX_HEADERS
    ${UART_CTX_DIR}/inc
)

# ==============================================================================
# Create source and header for READ
# ==============================================================================
set(UART_READ_DIR
    ${COMPONENT_NAME}/code/read
)

set(UART_READ_SOURCES
    # Add the path to each source file here
    ${UART_READ_DIR}/src/uart_is_available.c
    ${UART_READ_DIR}/src/uart_read_byte.c
)

set(UART_READ_HEADERS
    ${UART_READ_DIR}/inc
)

# ==============================================================================
# Create source and header for WRITE
# ==============================================================================
set(UART_WRITE_DIR
    ${COMPONENT_NAME}/code/write
)

set(UART_WRITE_SOURCES
    # Add the path to each source file here
    ${UART_WRITE_DIR}/src/uart_write_byte.c
)

set(UART_WRITE_HEADERS
    ${UART_WRITE_DIR}/inc
)

# ==============================================================================
# Create source and header for IRQ
# ==============================================================================
set(UART_IRQ_DIR
    ${COMPONENT_NAME}/code/irq
)

set(UART_IRQ_SOURCES
    # Add the path to each source file here
    ${UART_IRQ_DIR}/src/uart_irq_rx.c
)

set(UART_IRQ_HEADERS
    ${UART_IRQ_DIR}/inc
)

# ==============================================================================
# Create library kernel target for UART
# ==============================================================================
set(LIB_NAME_KRN ${UART_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${UART_IRQ_SOURCES}
        ${UART_CTX_SOURCES}
        ${UART_READ_SOURCES}
        ${UART_WRITE_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${UART_IRQ_HEADERS}
        ${UART_CTX_HEADERS}
        ${UART_READ_HEADERS}
        ${UART_WRITE_HEADERS}
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
        ${MMIO_LIB_NAME}_krn
        ${IRQ_LIB_NAME}_krn
        ${CONSOLE_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
