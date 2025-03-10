# ==============================================================================
# Create source and header for WRITE
# ==============================================================================
set(UART_WRITE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/write
)

set(UART_WRITE_SOURCES
    # Add the path to each source file here
    ${UART_WRITE_DIR}/src/uart_write.c
)

set (UART_WRITE_HEADERS
    ${UART_WRITE_DIR}/include
)

# ==============================================================================
# Create library target for UART
# ==============================================================================
set (LIB_NAME ${UART_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${UART_WRITE_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${UART_WRITE_HEADERS}
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
        ${MMIO_LIB_NAME}
    "-Wl,--no-whole-archive"
)
