# ==============================================================================
# Set the architecture name
# ==============================================================================
set(ARCH_PATH ${ARCH_PATH})
set(ARCH_NAME ${ARCH_NAME})

# ==============================================================================
# Create source and header for CORE
# ==============================================================================
set(IRQ_CORE_DIR
    ${ARCH_PATH}/code/core
)

set(IRQ_CORE_SOURCES
    # Add the path to each source file here
    ${IRQ_CORE_DIR}/src/irq_core_data.c
    ${IRQ_CORE_DIR}/src/irq_core_get_handler.c
    ${IRQ_CORE_DIR}/src/irq_core_init.c
    ${IRQ_CORE_DIR}/src/irq_core_register.c
)

set(IRQ_CORE_HEADERS
    ${IRQ_CORE_DIR}/inc
)

# ==============================================================================
# Create source and header for HANDLER
# ==============================================================================
set(IRQ_HANDLER_DIR
    ${ARCH_PATH}/code/handler
)

set(IRQ_HANDLER_SOURCES
    # Add the path to each source file here
    ${IRQ_HANDLER_DIR}/src/irq_handler_entry.c
    ${IRQ_HANDLER_DIR}/src/irq_handler.c
)

set(IRQ_HANDLER_HEADERS
    ${IRQ_HANDLER_DIR}/inc
)

# ==============================================================================
# Create library target for IRQ
# ==============================================================================
add_library(${ARCH_NAME}
    STATIC
        # Add the path to each source directory here
        ${IRQ_HANDLER_SOURCES}
        ${IRQ_CORE_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${ARCH_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${IRQ_HANDLER_HEADERS}
        ${IRQ_CORE_HEADERS}
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
        drivers.lib_gic
        drivers.lib_uart
        system.lib_printer
        libraries.lib_strings
        libraries.lib_stream
        system.lib_printer
)
