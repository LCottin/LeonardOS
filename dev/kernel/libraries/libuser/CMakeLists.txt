# ==============================================================================
# Set the library name
# ==============================================================================
set(LIB_NAME ${LIB_NAME})
set(LIB_PATH ${LIB_PATH})

# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(LIBUSER_UTILS_DIR
    ${LIB_PATH}/code/utils
)

set(LIBUSER_UTILS_SOURCES
    # Add the path to each source file here
    ${LIBUSER_UTILS_DIR}/src/user_sleep.c
)

set(LIBUSER_UTILS_HEADERS
    ${LIBUSER_UTILS_DIR}/inc
)

# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(LIBUSER_HANDLER_DIR
    ${LIB_PATH}/code/handler
)

set(LIBUSER_HANDLER_SOURCES
    # Add the path to each source file here
    ${LIBUSER_HANDLER_DIR}/src/libuser_console_get.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_get_time.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_launch_syscall.S
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_addr.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_char.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_formatted.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_int.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_string.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_yield.c
)

set(LIBUSER_HANDLER_HEADERS
    ${LIBUSER_HANDLER_DIR}/inc
)

# ==============================================================================
# Create library target for LIBUSER
# ==============================================================================
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${LIBUSER_UTILS_SOURCES}
        ${LIBUSER_HANDLER_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${LIBUSER_UTILS_HEADERS}
        ${LIBUSER_HANDLER_HEADERS}
        ${LIB_PATH}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${LIB_PATH}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE
        # Add the path to library of other folder here
        system.lib_syscall
        memory.lib_heap
        libraries.lib_formatter
        libraries.lib_stream
        system.lib_printer
        system.lib_clock
    PUBLIC
        arch.lib_types
        libraries.lib_strings
        libraries.lib_metadata
)
