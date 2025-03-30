# ==============================================================================
# Create source and header for IO64
# ==============================================================================
set(MMIO_IO64_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/io64
)

set(MMIO_IO64_SOURCES
    # Add the path to each source file here
    ${MMIO_IO64_DIR}/src/mmio_io64.c
)

set(MMIO_IO64_HEADERS
    ${MMIO_IO64_DIR}/include
)

# ==============================================================================
# Create source and header for IO32
# ==============================================================================
set(MMIO_IO32_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/io32
)

set(MMIO_IO32_SOURCES
    # Add the path to each source file here
    ${MMIO_IO32_DIR}/src/mmio_io32.c
)

set(MMIO_IO32_HEADERS
    ${MMIO_IO32_DIR}/include
)

# ==============================================================================
# Create source and header for IO16
# ==============================================================================
set(MMIO_IO16_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/io16
)

set(MMIO_IO16_SOURCES
    # Add the path to each source file here
    ${MMIO_IO16_DIR}/src/mmio_io16.c
)

set(MMIO_IO16_HEADERS
    ${MMIO_IO16_DIR}/include
)

# ==============================================================================
# Create source and header for IO8
# ==============================================================================
set(MMIO_IO8_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/io8
)

set(MMIO_IO8_SOURCES
    # Add the path to each source file here
    ${MMIO_IO8_DIR}/src/mmio_io8.c
)

set(MMIO_IO8_HEADERS
    ${MMIO_IO8_DIR}/include
)

# ==============================================================================
# Create library kernel target for MMIO
# ==============================================================================
set(LIB_NAME_KRN ${MMIO_LIB_NAME}_krn)
add_library(${LIB_NAME_KRN}
    STATIC
        # Add the path to each source file here
        ${MMIO_IO64_SOURCES}
        ${MMIO_IO32_SOURCES}
        ${MMIO_IO16_SOURCES}
        ${MMIO_IO8_SOURCES}
)

# ==============================================================================
# Add include directories for the library kernel
# ==============================================================================
target_include_directories(${LIB_NAME_KRN}
    PRIVATE
        # Add the path to each header directory here
        ${MMIO_IO64_HEADERS}
        ${MMIO_IO32_HEADERS}
        ${MMIO_IO16_HEADERS}
        ${MMIO_IO8_HEADERS}
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
