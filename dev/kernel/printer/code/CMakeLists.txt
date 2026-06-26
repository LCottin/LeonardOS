# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for PRINT
# ==============================================================================
set(PRINTER_PRINT_DIR
    ${COMPONENT_NAME}/code/print
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
    ${COMPONENT_NAME}/code/stream
)

set(PRINTER_STREAM_SOURCES
    # Add the path to each source file here
    ${PRINTER_STREAM_DIR}/src/printer_stream_string.c
)

set(PRINTER_STREAM_HEADERS
    ${PRINTER_STREAM_DIR}/inc
)

# ==============================================================================
# Create library kernel target for PRINTER
# ==============================================================================
set(LIB_NAME_KRN ${PRINTER_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${PRINTER_STREAM_SOURCES}
        ${PRINTER_PRINT_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${PRINTER_STREAM_HEADERS}
        ${PRINTER_PRINT_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${UART_LIB_NAME}_krn
        ${STRINGS_LIB_NAME}_krn
        ${FORMATTER_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
