# ==============================================================================
# Set the system name
# ==============================================================================
set(SYS_PATH ${SYS_PATH})
set(SYS_NAME ${SYS_NAME})

# ==============================================================================
# Create source and header for PRINT
# ==============================================================================
set(PRINTER_PRINT_DIR
    ${SYS_PATH}/code/print
)

set(PRINTER_PRINT_SOURCES
    # Add the path to each source file here
    ${PRINTER_PRINT_DIR}/src/printer_print_address.c
    ${PRINTER_PRINT_DIR}/src/printer_print_char.c
    ${PRINTER_PRINT_DIR}/src/printer_print_formatted.c
    ${PRINTER_PRINT_DIR}/src/printer_print_signed.c
    ${PRINTER_PRINT_DIR}/src/printer_print_unsigned.c
    ${PRINTER_PRINT_DIR}/src/printer_print_long_signed.c
    ${PRINTER_PRINT_DIR}/src/printer_print_long_unsigned.c
    ${PRINTER_PRINT_DIR}/src/printer_print_string.c
)

set(PRINTER_PRINT_HEADERS
    ${PRINTER_PRINT_DIR}/inc
)

# ==============================================================================
# Create source and header for STREAM
# ==============================================================================
set(PRINTER_STREAM_DIR
    ${SYS_PATH}/code/stream
)

set(PRINTER_STREAM_SOURCES
    # Add the path to each source file here
    ${PRINTER_STREAM_DIR}/src/printer_stream_data.c
    ${PRINTER_STREAM_DIR}/src/printer_stream_get.c
    ${PRINTER_STREAM_DIR}/src/printer_stream_print_byte.c
)

set(PRINTER_STREAM_HEADERS
    ${PRINTER_STREAM_DIR}/inc
)

# ==============================================================================
# Create library target for PRINTER
# ==============================================================================
add_library(${SYS_NAME}
    STATIC
        # Add the path to each source file here
        ${PRINTER_STREAM_SOURCES}
        ${PRINTER_PRINT_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${SYS_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${PRINTER_STREAM_HEADERS}
        ${PRINTER_PRINT_HEADERS}
    PUBLIC
        ${SYS_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${SYS_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        drivers.lib_uart
        libraries.lib_strings
        libraries.lib_formatter
        libraries.lib_stream
)
