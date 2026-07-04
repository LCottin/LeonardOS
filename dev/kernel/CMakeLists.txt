# Define each component
set(COMPONENTS_DIR
    # Add the path to each component here
    "formatter"
    "irq"
    "gic"
    "seh"
    "printer"
    "scheduler"
    "pcb"
    "elf"
    "libuser"
    "syscall"
    "boot"
    "memory"
    "memory_ops"
    "strings"
    "containers"
    "uart"
    "mmio"
    "fpu"
    "core"
    "clock"
    "bmt"
)

# Define each library
set(LIBRARIES_DIR
    # Add the path to each library here
    "types"
    "stream"
)

# Define each binary
set (BINARIES_DIR
    "boot_bin"
    "core_bin"
)

# Each entry is "source/path:bin_name" (colon-separated).
set(TESTS_DIR
    "memory_ops/test/utils/copy:memory_ops_utils_copy"
    "memory_ops/test/utils/set:memory_ops_utils_set"
    "memory_ops/test/utils/cmp:memory_ops_utils_cmp"
    "mmio/test/io8/clear_bit:mmio_io8_clear_bit"
    "mmio/test/io8/read:mmio_io8_read"
    "mmio/test/io8/set_bit:mmio_io8_set_bit"
    "mmio/test/io8/toggle_bit:mmio_io8_toggle_bit"
    "mmio/test/io8/write:mmio_io8_write"
    "mmio/test/io16/clear_bit:mmio_io16_clear_bit"
    "mmio/test/io16/read:mmio_io16_read"
    "mmio/test/io16/set_bit:mmio_io16_set_bit"
    "mmio/test/io16/toggle_bit:mmio_io16_toggle_bit"
    "mmio/test/io16/write:mmio_io16_write"
    "mmio/test/io32/clear_bit:mmio_io32_clear_bit"
    "mmio/test/io32/read:mmio_io32_read"
    "mmio/test/io32/set_bit:mmio_io32_set_bit"
    "mmio/test/io32/toggle_bit:mmio_io32_toggle_bit"
    "mmio/test/io32/write:mmio_io32_write"
    "mmio/test/io64/clear_bit:mmio_io64_clear_bit"
    "mmio/test/io64/read:mmio_io64_read"
    "mmio/test/io64/set_bit:mmio_io64_set_bit"
    "mmio/test/io64/toggle_bit:mmio_io64_toggle_bit"
    "mmio/test/io64/write:mmio_io64_write"
)

# ==============================================================================
# Compile libraries
# ==============================================================================
foreach(LIBRARY_DIR ${LIBRARIES_DIR})
    add_subdirectory_custom(${KERNEL_DIR}/${LIBRARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIR})
endforeach()

# ==============================================================================
# Compile components
# ==============================================================================
foreach(COMPONENT_DIR ${COMPONENTS_DIR})
    add_subdirectory_custom(${KERNEL_DIR}/${COMPONENT_DIR}/code ${CMAKE_CURRENT_SOURCE_DIR}/${COMPONENT_DIR})
endforeach()

# ==============================================================================
# Compile binaries
# ==============================================================================
foreach(BINARY_DIR ${BINARIES_DIR})
    add_subdirectory(${KERNEL_DIR}/${BINARY_DIR})
endforeach()

# ==============================================================================
# Compile each test.
# Split "source/path:bin_name" on the colon to get both parts independently.
# ==============================================================================

set(TEST_LINKER_SCRIPT ${KERNEL_DIR}/spec/linker.ld)
add_subdirectory_custom(${KERNEL_DIR}/spec/code ${CMAKE_CURRENT_SOURCE_DIR}/spec)

foreach(TEST_ENTRY ${TESTS_DIR})
    string(REPLACE ":" ";" TEST_PARTS ${TEST_ENTRY})
    list(GET TEST_PARTS 0 TEST_SRC_PATH)
    list(GET TEST_PARTS 1 BIN_NAME)

    # add_subdirectory_custom_test(relative_path, absolute_source_path, bin_name)
    add_subdirectory_custom_test(${TEST_SRC_PATH} ${KERNEL_DIR}/${TEST_SRC_PATH} ${BIN_NAME})

    set_property(GLOBAL APPEND PROPERTY ALL_TESTS ${BIN_NAME}.elf)
endforeach()

# ==============================================================================
# Aggregate target: build every test with "cmake --build . --target tests"
# ==============================================================================
get_property(ALL_TESTS GLOBAL PROPERTY ALL_TESTS)
if(ALL_TESTS)
    add_custom_target(tests DEPENDS ${ALL_TESTS})
endif()
