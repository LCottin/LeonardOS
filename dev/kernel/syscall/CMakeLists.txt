# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(SYSCALL_HANDLER_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/handler
)

set(SYSCALL_HANDLER_SOURCES
    # Add the path to each source file here
    ${SYSCALL_HANDLER_DIR}/src/syscall_handler.c
)

set(SYSCALL_HANDLER_HEADERS
    ${SYSCALL_HANDLER_DIR}/include
)

# ==============================================================================
# Create library kernel target for SYSCALL
# ==============================================================================
set(LIB_NAME_KRN ${SYSCALL_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${SYSCALL_HANDLER_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${SYSCALL_HANDLER_HEADERS}
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
        ${PRINTER_LIB_NAME}_krn
        ${CLOCK_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)

# ==============================================================================
# Create library kernuserel target for SYSCALL
# ==============================================================================
set(LIB_NAME_USR ${SYSCALL_LIB_NAME}_usr)
add_library(${LIB_NAME_USR}
    STATIC
        # Add the path to each source file here
        ${SYSCALL_HANDLER_SOURCES}
)

# ==============================================================================
# Add include directories for the library user
# ==============================================================================
target_include_directories(${LIB_NAME_USR}
    PRIVATE
        # Add the path to each header directory here
        ${SYSCALL_HANDLER_HEADERS}
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
        ${TYPES_LIB_NAME}_usr
        ${PRINTER_LIB_NAME}_krn
        ${CLOCK_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
