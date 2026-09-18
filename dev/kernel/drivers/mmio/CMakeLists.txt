# ==============================================================================
# Set the driver name
# ==============================================================================
set(DRV_PATH ${DRV_PATH})
set(DRV_NAME ${DRV_NAME})

# ==============================================================================
# Create source and header for IO64
# ==============================================================================
set(MMIO_IO64_DIR
    ${DRV_PATH}/code/io64
)

set(MMIO_IO64_SOURCES
    # Add the path to each source file here
    ${MMIO_IO64_DIR}/src/mmio_io64_clear_bit.c
    ${MMIO_IO64_DIR}/src/mmio_io64_read.c
    ${MMIO_IO64_DIR}/src/mmio_io64_set_bit.c
    ${MMIO_IO64_DIR}/src/mmio_io64_toggle_bit.c
    ${MMIO_IO64_DIR}/src/mmio_io64_write.c
)

set(MMIO_IO64_HEADERS
    ${MMIO_IO64_DIR}/inc
)

# ==============================================================================
# Create source and header for IO32
# ==============================================================================
set(MMIO_IO32_DIR
    ${DRV_PATH}/code/io32
)

set(MMIO_IO32_SOURCES
    # Add the path to each source file here
    ${MMIO_IO32_DIR}/src/mmio_io32_clear_bit.c
    ${MMIO_IO32_DIR}/src/mmio_io32_read.c
    ${MMIO_IO32_DIR}/src/mmio_io32_set_bit.c
    ${MMIO_IO32_DIR}/src/mmio_io32_toggle_bit.c
    ${MMIO_IO32_DIR}/src/mmio_io32_write.c
)

set(MMIO_IO32_HEADERS
    ${MMIO_IO32_DIR}/inc
)

# ==============================================================================
# Create source and header for IO16
# ==============================================================================
set(MMIO_IO16_DIR
    ${DRV_PATH}/code/io16
)

set(MMIO_IO16_SOURCES
    # Add the path to each source file here
    ${MMIO_IO16_DIR}/src/mmio_io16_clear_bit.c
    ${MMIO_IO16_DIR}/src/mmio_io16_read.c
    ${MMIO_IO16_DIR}/src/mmio_io16_set_bit.c
    ${MMIO_IO16_DIR}/src/mmio_io16_toggle_bit.c
    ${MMIO_IO16_DIR}/src/mmio_io16_write.c
)

set(MMIO_IO16_HEADERS
    ${MMIO_IO16_DIR}/inc
)

# ==============================================================================
# Create source and header for IO8
# ==============================================================================
set(MMIO_IO8_DIR
    ${DRV_PATH}/code/io8
)

set(MMIO_IO8_SOURCES
    # Add the path to each source file here
    ${MMIO_IO8_DIR}/src/mmio_io8_clear_bit.c
    ${MMIO_IO8_DIR}/src/mmio_io8_read.c
    ${MMIO_IO8_DIR}/src/mmio_io8_set_bit.c
    ${MMIO_IO8_DIR}/src/mmio_io8_toggle_bit.c
    ${MMIO_IO8_DIR}/src/mmio_io8_write.c
)

set(MMIO_IO8_HEADERS
    ${MMIO_IO8_DIR}/inc
)

# ==============================================================================
# Create library target for MMIO
# ==============================================================================
add_library(${DRV_NAME}
    STATIC
        # Add the path to each source file here
        ${MMIO_IO64_SOURCES}
        ${MMIO_IO32_SOURCES}
        ${MMIO_IO16_SOURCES}
        ${MMIO_IO8_SOURCES}
)

# ==============================================================================
# Add include directories for the library
# ==============================================================================
target_include_directories(${DRV_NAME}
    PRIVATE
        # Add the path to each header directory here
        ${MMIO_IO64_HEADERS}
        ${MMIO_IO32_HEADERS}
        ${MMIO_IO16_HEADERS}
        ${MMIO_IO8_HEADERS}
    PUBLIC
        ${DRV_PATH}/inc/krn     # Private headers for kernel implementation
)

# ==============================================================================
# Add library dependencies
# ==============================================================================
target_link_libraries(${DRV_NAME}
    PRIVATE
        # Add the path to library of other folder here
        arch.lib_types
)
