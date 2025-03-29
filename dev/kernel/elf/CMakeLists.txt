# ==============================================================================
# Create source and header for CHECK
# ==============================================================================
set(ELF_CHECK_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/check
)

set(ELF_CHECK_SOURCES
    # Add the path to each source file here
    ${ELF_CHECK_DIR}/src/elf_check_is_compatible.c
    ${ELF_CHECK_DIR}/src/elf_check_is_segment_metadata.c
    ${ELF_CHECK_DIR}/src/elf_check_match_magic.c
)

set(ELF_CHECK_HEADERS
    ${ELF_CHECK_DIR}/include
)

# ==============================================================================
# Create source and header for BUILD
# ==============================================================================
set(ELF_BUILD_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/build
)

set(ELF_BUILD_SOURCES
    # Add the path to each source file here
    ${ELF_BUILD_DIR}/src/elf_build_meta_info.c
    ${ELF_BUILD_DIR}/src/elf_build_segment_info.c
    ${ELF_BUILD_DIR}/src/elf_build_convert_magic_to_type.c
)

set(ELF_BUILD_HEADERS
    ${ELF_BUILD_DIR}/include
)

# ==============================================================================
# Create source and header for INFO
# ==============================================================================
set(ELF_INFO_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/info
)

set(ELF_INFO_SOURCES
    # Add the path to each source file here
    ${ELF_INFO_DIR}/src/elf_info_get_entry_point.c
    ${ELF_INFO_DIR}/src/elf_info_get_type.c
    ${ELF_INFO_DIR}/src/elf_info_get_nb_segments.c
)

set(ELF_INFO_HEADERS
    ${ELF_INFO_DIR}/include
)

# ==============================================================================
# Create library kernel target for ELF
# ==============================================================================
set(LIB_NAME_KRN ${ELF_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${ELF_CHECK_SOURCES}
        ${ELF_BUILD_SOURCES}
        ${ELF_INFO_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${ELF_CHECK_HEADERS}
        ${ELF_BUILD_HEADERS}
        ${ELF_INFO_HEADERS}
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
    "-Wl,--no-whole-archive"
)
