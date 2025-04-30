# ==============================================================================
# Create source and header for PRINT
# ==============================================================================
set(SERIAL_PRINT_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/print
)

set(SERIAL_PRINT_SOURCES
    # Add the path to each source file here
    ${SERIAL_PRINT_DIR}/src/serial_print.c
)

set(SERIAL_PRINT_HEADERS
    ${SERIAL_PRINT_DIR}/include
)

# ==============================================================================
# Create library kernel target for SERIAL
# ==============================================================================
set(LIB_NAME_KRN ${SERIAL_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${SERIAL_PRINT_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${SERIAL_PRINT_HEADERS}
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
        ${UART_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
