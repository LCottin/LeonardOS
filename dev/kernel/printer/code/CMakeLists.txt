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
# Create library kernel target for PRINTER
# ==============================================================================
set(LIB_NAME_KRN ${PRINTER_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${PRINTER_PRINT_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
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
        ${STRINGS_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Create library user target for PRINTER
# ==============================================================================
set(LIB_NAME_USR ${PRINTER_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${PRINTER_PRINT_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${PRINTER_PRINT_HEADERS}
        ${COMPONENT_NAME}/inc/krn     # Private headers for user implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${UART_LIB_NAME}_krn
    PUBLIC
        ${TYPES_LIB_NAME}_usr
        ${STRINGS_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
