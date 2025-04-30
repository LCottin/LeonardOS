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

set(UART_WRITE_HEADERS
    ${UART_WRITE_DIR}/include
)

# ==============================================================================
# Create library kernel target for UART
# ==============================================================================
set(LIB_NAME_KRN ${UART_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${UART_WRITE_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${UART_WRITE_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${MMIO_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
