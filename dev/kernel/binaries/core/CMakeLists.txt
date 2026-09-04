# ==============================================================================
# Set the library name
# ==============================================================================
set(LIB_NAME ${LIB_NAME})
set(LIB_PATH ${LIB_PATH})

# ==============================================================================
# Create source and header for MAIN
# ==============================================================================
set(CORE_MAIN_DIR
    ${LIB_PATH}/code/main
)

set(CORE_MAIN_SOURCES
    # Add the path to each source file here
    ${CORE_MAIN_DIR}/src/core_main.c
)

set(CORE_MAIN_HEADERS
    ${CORE_MAIN_DIR}/inc
)

# ==============================================================================
# Create library target for CORE
# ==============================================================================
add_library(${LIB_NAME}
    STATIC
        # Add the path to each source file here
        ${CORE_MAIN_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${LIB_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${CORE_MAIN_HEADERS}
    PUBLIC
        ${LIB_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library kernel dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
        system.lib_printer
        libraries.lib_strings
        memory.lib_heap
        memory.lib_tools
        arch.lib_fpu
        system.lib_clock
        system.lib_pcb
        system.lib_scheduler
        system.lib_bmt
        system.lib_elf
        drivers.lib_gic
        arch.lib_irq
        libraries.lib_formatter
        libraries.lib_stream
        drivers.lib_uart
        drivers.lib_console
        arch.lib_seh
        libraries.lib_metadata
)
