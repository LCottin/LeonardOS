# ==============================================================================
# Create source and header for INIT
# ==============================================================================
set(SCHEDULER_INIT_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/init
)

set(SCHEDULER_INIT_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_INIT_DIR}/src/scheduler_init.c
)

set(SCHEDULER_INIT_HEADERS
    ${SCHEDULER_INIT_DIR}/include
)

# ==============================================================================
# Create source and header for RUN
# ==============================================================================
set(SCHEDULER_RUN_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/run
)

set(SCHEDULER_RUN_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_RUN_DIR}/src/scheduler_run.c
)

set(SCHEDULER_RUN_HEADERS
    ${SCHEDULER_RUN_DIR}/include
)

# ==============================================================================
# Create source and header for SWITCH
# ==============================================================================
set(SCHEDULER_SWITCH_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/switch
)

set(SCHEDULER_SWITCH_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_SWITCH_DIR}/src/scheduler_switch_task.S
)

set(SCHEDULER_SWITCH_HEADERS
    ${SCHEDULER_SWITCH_DIR}/include
)

# ==============================================================================
# Create source and header for CTX
# ==============================================================================
set(SCHEDULER_CTX_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/ctx
)

set(SCHEDULER_CTX_SOURCES
    # Add the path to each source file here
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_data.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_get_current_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_get_next_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_set_current_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_add_task.c
    ${SCHEDULER_CTX_DIR}/src/scheduler_ctx_init.c
)

set(SCHEDULER_CTX_HEADERS
    ${SCHEDULER_CTX_DIR}/include
)


# ==============================================================================
# Create library kernel target for SCHEDULER
# ==============================================================================
set(LIB_NAME_KRN ${SCHEDULER_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source directory here
        ${SCHEDULER_INIT_SOURCES}
        ${SCHEDULER_RUN_SOURCES}
        ${SCHEDULER_SWITCH_SOURCES}
        ${SCHEDULER_CTX_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${SCHEDULER_INIT_HEADERS}
        ${SCHEDULER_RUN_HEADERS}
        ${SCHEDULER_SWITCH_HEADERS}
        ${SCHEDULER_CTX_HEADERS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/krn     # Private headers for kernel implementation
        ${CMAKE_CURRENT_SOURCE_DIR}/include/usr     # Public headers for user interface
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${LIB_NAME_KRN}
    PRIVATE "-Wl,--whole-archive"
        # Add the path to library of other folder here
        ${TYPES_LIB_NAME}_krn
        ${BMT_LIB_NAME}_krn
        ${ELF_LIB_NAME}_krn
        ${PCB_LIB_NAME}_krn
        ${MEMORY_OPS_LIB_NAME}_krn
        ${PRINTER_LIB_NAME}_krn
        ${STRINGS_LIB_NAME}_krn
    "-Wl,--no-whole-archive"
)
