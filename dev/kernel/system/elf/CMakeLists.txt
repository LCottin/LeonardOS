# ==============================================================================
# Set the system name
# ==============================================================================
set(SYS_PATH ${SYS_PATH})
set(SYS_NAME ${SYS_NAME})

# ==============================================================================
# Create source and header for CHECK
# ==============================================================================
set(ELF_CHECK_DIR
    ${SYS_PATH}/code/check
)

set(ELF_CHECK_SOURCES
    # Add the path to each source file here
    ${ELF_CHECK_DIR}/src/elf_check_is_compatible.c
    ${ELF_CHECK_DIR}/src/elf_check_is_segment_metadata.c
    ${ELF_CHECK_DIR}/src/elf_check_match_magic.c
)

set(ELF_CHECK_HEADERS
    ${ELF_CHECK_DIR}/inc
)

# ==============================================================================
# Create source and header for BUILD
# ==============================================================================
set(ELF_BUILD_DIR
    ${SYS_PATH}/code/build
)

set(ELF_BUILD_SOURCES
    # Add the path to each source file here
    ${ELF_BUILD_DIR}/src/elf_build_meta_info.c
    ${ELF_BUILD_DIR}/src/elf_build_binary_info.c
)

set(ELF_BUILD_HEADERS
    ${ELF_BUILD_DIR}/inc
)

# ==============================================================================
# Create source and header for INFO
# ==============================================================================
set(ELF_INFO_DIR
    ${SYS_PATH}/code/info
)

set(ELF_INFO_SOURCES
    # Add the path to each source file here
    ${ELF_INFO_DIR}/src/elf_info_get_entry_point.c
    ${ELF_INFO_DIR}/src/elf_info_get_type.c
    ${ELF_INFO_DIR}/src/elf_info_get_nb_segments.c
)

set(ELF_INFO_HEADERS
    ${ELF_INFO_DIR}/inc
)

# ==============================================================================
# Create library target for ELF
# ==============================================================================
add_library(${SYS_NAME}
    STATIC
        # Add the path to each source file here
        ${ELF_CHECK_SOURCES}
        ${ELF_BUILD_SOURCES}
        ${ELF_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${SYS_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${ELF_CHECK_HEADERS}
        ${ELF_BUILD_HEADERS}
        ${ELF_INFO_HEADERS}
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
        libraries.lib_metadata
        memory.lib_tools
)
