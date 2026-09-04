# ==============================================================================
# Set the architecture name
# ==============================================================================
set(ARCH_PATH ${ARCH_PATH})
set(ARCH_NAME ${ARCH_NAME})

# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(SEH_HANDLER_DIR
    ${ARCH_PATH}/code/handler
)

set(SEH_HANDLER_SOURCES
    # Add the path to each source file here
    ${SEH_HANDLER_DIR}/src/seh_handler.c
    ${SEH_HANDLER_DIR}/src/seh_handler_fiq.S
    ${SEH_HANDLER_DIR}/src/seh_handler_irq.S
    ${SEH_HANDLER_DIR}/src/seh_handler_serr.S
    ${SEH_HANDLER_DIR}/src/seh_handler_sync.S
)

set(SEH_HANDLER_HEADERS
    ${SEH_HANDLER_DIR}/inc
)

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(SEH_CTX_DIR
    ${ARCH_PATH}/code/ctx
)

set(SEH_CTX_SOURCES
    # Add the path to each source file here
    ${SEH_CTX_DIR}/src/seh_ctx_init.S
    ${SEH_CTX_DIR}/src/seh_ctx_exception_table.S
)

set(SEH_CTX_HEADERS
    ${SEH_CTX_DIR}/inc
)

# ==============================================================================
# Create library target for SEH
# ==============================================================================
add_library(${ARCH_NAME}
    STATIC
        # Add the path to each source directory here
        ${SEH_HANDLER_SOURCES}
        ${SEH_CTX_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${ARCH_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${SEH_HANDLER_HEADERS}
        ${SEH_CTX_HEADERS}
    PUBLIC
        ${ARCH_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${ARCH_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        libraries.lib_strings
        system.lib_printer
        arch.lib_irq
        drivers.lib_gic
        libraries.lib_formatter
        libraries.lib_stream
        system.lib_syscall
)
