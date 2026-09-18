# ==============================================================================
# Set the driver name
# ==============================================================================
set(DRV_PATH ${DRV_PATH})
set(DRV_NAME ${DRV_NAME})

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(UART_CTX_DIR
    ${DRV_PATH}/code/ctx
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
    ${DRV_PATH}/code/read
)

set(UART_READ_SOURCES
    # Add the path to each source file here
    ${UART_READ_DIR}/src/uart_read_byte.c
)

set(UART_READ_HEADERS
    ${UART_READ_DIR}/inc
)

# ==============================================================================
# Create source and header for WRITE
# ==============================================================================
set(UART_WRITE_DIR
    ${DRV_PATH}/code/write
)

set(UART_WRITE_SOURCES
    # Add the path to each source file here
    ${UART_WRITE_DIR}/src/uart_write_byte.c
)

set(UART_WRITE_HEADERS
    ${UART_WRITE_DIR}/inc
)

# ==============================================================================
# Create library target for UART
# ==============================================================================
add_library(${DRV_NAME}
    STATIC
        # Add the path to each source file here
        ${UART_CTX_SOURCES}
        ${UART_READ_SOURCES}
        ${UART_WRITE_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${DRV_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${UART_CTX_HEADERS}
        ${UART_READ_HEADERS}
        ${UART_WRITE_HEADERS}
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
        drivers.lib_mmio
)
