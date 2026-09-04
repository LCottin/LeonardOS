# ==============================================================================
# Set the system name
# ==============================================================================
set(SYS_PATH ${SYS_PATH})
set(SYS_NAME ${SYS_NAME})

# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(SYSCALL_HANDLER_DIR
    ${SYS_PATH}/code/handler
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
# Create library target for SYSCALL
# ==============================================================================
add_library(${SYS_NAME}
    STATIC
        # Add the path to each source file here
        ${SYSCALL_HANDLER_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${SYS_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${SYSCALL_HANDLER_HEADERS}
    PUBLIC
        ${SYS_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${SYS_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        system.lib_printer
        libraries.lib_strings
        system.lib_clock
        system.lib_scheduler
        system.lib_pcb
        libraries.lib_formatter
        memory.lib_tools
        libraries.lib_stream
        drivers.lib_console
)
