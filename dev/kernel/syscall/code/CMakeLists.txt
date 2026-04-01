# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(SYSCALL_HANDLER_DIR
    ${COMPONENT_NAME}/code/handler
)

set(SYSCALL_HANDLER_SOURCES
    # Add the path to each source file here
    ${SYSCALL_HANDLER_DIR}/src/syscall_handler.S
    ${SYSCALL_HANDLER_DIR}/src/syscall_manager.c
)

set(SYSCALL_HANDLER_HEADERS
    ${SYSCALL_HANDLER_DIR}/inc
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
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
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
        ${SCHEDULER_LIB_NAME}_krn
        ${PCB_LIB_NAME}_krn
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
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
    PUBLIC
        ${COMPONENT_NAME}/inc/usr     # Public headers for user interface
)

# ==============================================================================
# Add library user dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_USR}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${PRINTER_LIB_NAME}_krn
        ${CLOCK_LIB_NAME}_krn
        ${SCHEDULER_LIB_NAME}_krn
        ${PCB_LIB_NAME}_krn
    PUBLIC
        ${TYPES_LIB_NAME}_usr
    "-Wl,--no-whole-archive"
)
