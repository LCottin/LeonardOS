# ==============================================================================
# Create source and header for UTILS
# ==============================================================================
set(LIBUSER_UTILS_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

set(LIBUSER_UTILS_SOURCES
    # Add the path to each source file here
    ${LIBUSER_UTILS_DIR}/src/user_sleep.c
)

set(LIBUSER_UTILS_HEADERS
    ${LIBUSER_UTILS_DIR}/include
)

# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(LIBUSER_HANDLER_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/handler
)

set(LIBUSER_HANDLER_SOURCES
    # Add the path to each source file here
    ${LIBUSER_HANDLER_DIR}/src/libuser_get_time.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_string.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_int.c
    ${LIBUSER_HANDLER_DIR}/src/libuser_print_addr.c
)

set(LIBUSER_HANDLER_HEADERS
    ${LIBUSER_HANDLER_DIR}/include
)

# ==============================================================================
# Create library user target for LIBUSER
# ==============================================================================
set(LIB_NAME_USR ${LIBUSER_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${LIBUSER_UTILS_SOURCES}
        ${LIBUSER_HANDLER_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${LIBUSER_UTILS_HEADERS}
        ${LIBUSER_HANDLER_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${SYSCALL_LIB_NAME}_krn
        ${MEMORY_LIB_NAME}_krn
    PUBLIC
        ${TYPES_LIB_NAME}_usr
        ${PRINTER_LIB_NAME}_usr
        ${CLOCK_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
