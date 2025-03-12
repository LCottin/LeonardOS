# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(LIBUSER_HANDLER_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/handler
)

set(LIBUSER_HANDLER_SOURCES
    # Add the path to each source file here
    ${LIBUSER_HANDLER_DIR}/src/libuser_usr.c
)

set (LIBUSER_HANDLER_HEADERS
    ${LIBUSER_HANDLER_DIR}/include
)

# ==============================================================================
# Create library target for LIBUSER
# ==============================================================================
set (LIB_NAME ${LIBUSER_LIB_NAME})
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${LIBUSER_HANDLER_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${LIBUSER_HANDLER_HEADERS}
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
        ${SYSCALL_LIB_NAME}
    "-Wl,--no-whole-archive"
)
