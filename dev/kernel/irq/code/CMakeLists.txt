# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for CORE
# ==============================================================================
set(IRQ_CORE_DIR
    ${COMPONENT_NAME}/code/core
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
    ${COMPONENT_NAME}/code/handler
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
# Create library kernel target for IRQ
# ==============================================================================
set(LIB_NAME_KRN ${IRQ_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source directory here
        ${IRQ_HANDLER_SOURCES}
        ${IRQ_CORE_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${IRQ_HANDLER_HEADERS}
        ${IRQ_CORE_HEADERS}
    PUBLIC
        ${COMPONENT_NAME}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${GIC_LIB_NAME}_krn
        ${UART_LIB_NAME}_krn
        ${PRINTER_LIB_NAME}_krn
        ${STRINGS_LIB_NAME}_krn
        ${STREAM_LIB_NAME}_krn
)
