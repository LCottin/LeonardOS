# Each entry is "source/path:bin_name" (colon-separated).
set(UNIT_TEST_LIST
    #######################################################
    # ARCH unit tests
    #######################################################


    #######################################################
    # BINARIES unit tests
    #######################################################


    #######################################################
    # DRIVERS unit tests
    #######################################################
    "${DRIVERS_PATH}/console/test/buffer/pop:console_buffer_pop"
    "${DRIVERS_PATH}/console/test/buffer/push:console_buffer_push"
    "${DRIVERS_PATH}/console/test/ctx/ctx_init:console_ctx_init"
    "${DRIVERS_PATH}/console/test/irq/irq_rx:console_irq_rx"
    "${DRIVERS_PATH}/console/test/buffer/is_empty:console_buffer_is_empty"

    "${DRIVERS_PATH}/mmio/test/io8/clear_bit:mmio_io8_clear_bit"
    "${DRIVERS_PATH}/mmio/test/io8/read:mmio_io8_read"
    "${DRIVERS_PATH}/mmio/test/io8/set_bit:mmio_io8_set_bit"
    "${DRIVERS_PATH}/mmio/test/io8/toggle_bit:mmio_io8_toggle_bit"
    "${DRIVERS_PATH}/mmio/test/io8/write:mmio_io8_write"
    "${DRIVERS_PATH}/mmio/test/io16/clear_bit:mmio_io16_clear_bit"
    "${DRIVERS_PATH}/mmio/test/io16/read:mmio_io16_read"
    "${DRIVERS_PATH}/mmio/test/io16/set_bit:mmio_io16_set_bit"
    "${DRIVERS_PATH}/mmio/test/io16/toggle_bit:mmio_io16_toggle_bit"
    "${DRIVERS_PATH}/mmio/test/io16/write:mmio_io16_write"
    "${DRIVERS_PATH}/mmio/test/io32/clear_bit:mmio_io32_clear_bit"
    "${DRIVERS_PATH}/mmio/test/io32/read:mmio_io32_read"
    "${DRIVERS_PATH}/mmio/test/io32/set_bit:mmio_io32_set_bit"
    "${DRIVERS_PATH}/mmio/test/io32/toggle_bit:mmio_io32_toggle_bit"
    "${DRIVERS_PATH}/mmio/test/io32/write:mmio_io32_write"
    "${DRIVERS_PATH}/mmio/test/io64/clear_bit:mmio_io64_clear_bit"
    "${DRIVERS_PATH}/mmio/test/io64/read:mmio_io64_read"
    "${DRIVERS_PATH}/mmio/test/io64/set_bit:mmio_io64_set_bit"
    "${DRIVERS_PATH}/mmio/test/io64/toggle_bit:mmio_io64_toggle_bit"
    "${DRIVERS_PATH}/mmio/test/io64/write:mmio_io64_write"

    "${DRIVERS_PATH}/uart/test/write/write_byte:uart_write_byte"
    "${DRIVERS_PATH}/uart/test/read/read_byte:uart_read_byte"
    "${DRIVERS_PATH}/uart/test/ctx/ctx_init:uart_ctx_init"

    #######################################################
    # LIBRARIES unit tests
    #######################################################
    "${LIBRARIES_PATH}/containers/test/ring_buffer/init:containers_ring_buffer_init"
    "${LIBRARIES_PATH}/containers/test/ring_buffer/is_empty:containers_ring_buffer_is_empty"
    "${LIBRARIES_PATH}/containers/test/ring_buffer/pop:containers_ring_buffer_pop"
    "${LIBRARIES_PATH}/containers/test/ring_buffer/push:containers_ring_buffer_push"


    #######################################################
    # MEMORY unit tests
    #######################################################
    "${MEMORY_PATH}/tools/test/utils/copy:memory_ops_utils_copy"
    "${MEMORY_PATH}/tools/test/utils/set:memory_ops_utils_set"
    "${MEMORY_PATH}/tools/test/utils/cmp:memory_ops_utils_cmp"


    #######################################################
    # PLATFORM unit tests
    #######################################################


    #######################################################
    # SYSTEM unit tests
    #######################################################
    "${SYSTEM_PATH}/printer/test/print/print_string:printer_print_string"
    "${SYSTEM_PATH}/syscall/test/handler/syscall_manager:syscall_manager"
)

# ==============================================================================
# Compile each test.
# Split "source/path:bin_name" on the colon to get both parts independently.
# ==============================================================================
set(TEST_LINKER_SCRIPT ${LIBRARIES_PATH}/test/linker.ld)
build_library(
    ${LIBRARIES_PATH}/test
    libraries.lib_test)

foreach(TEST_ENTRY ${UNIT_TEST_LIST})
    string(REPLACE ":" ";" TEST_PARTS ${TEST_ENTRY})
    list(GET TEST_PARTS 0 TEST_SRC_PATH)
    list(GET TEST_PARTS 1 BIN_NAME)

    build_test(
        ${TEST_SRC_PATH}
        ${TEST_SRC_PATH}
        ${BIN_NAME})

    set_property(GLOBAL APPEND PROPERTY ALL_TESTS ${BIN_NAME}.elf)
endforeach()

# ==============================================================================
# Aggregate target: build every test with "cmake --build . --target tests"
# ==============================================================================
get_property(ALL_TESTS GLOBAL PROPERTY ALL_TESTS)
if(ALL_TESTS)
    add_custom_target(tests DEPENDS ${ALL_TESTS})
endif()
