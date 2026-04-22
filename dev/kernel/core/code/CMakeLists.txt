# ==============================================================================
# Set the component name
# ==============================================================================
set(COMPONENT_NAME ${ARG})

# ==============================================================================
# Create source and header for MAIN
# ==============================================================================
set(CORE_MAIN_DIR
    ${COMPONENT_NAME}/code/main
)

set(CORE_MAIN_SOURCES
    # Add the path to each source file here
    ${CORE_MAIN_DIR}/src/core_main.c
)

set(CORE_MAIN_HEADERS
    ${CORE_MAIN_DIR}/inc
)

# ==============================================================================
# Create library kernel target for CORE
# ==============================================================================
set(LIB_NAME_KRN ${CORE_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${CORE_MAIN_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${CORE_MAIN_HEADERS}
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
        ${STRINGS_LIB_NAME}_krn
        ${MEMORY_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
        ${FPU_LIB_NAME}_krn
        ${CLOCK_LIB_NAME}_krn
        ${PCB_LIB_NAME}_krn
        ${SCHEDULER_LIB_NAME}_krn
        ${BMT_LIB_NAME}_krn
        ${ELF_LIB_NAME}_krn
        ${SEH_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
