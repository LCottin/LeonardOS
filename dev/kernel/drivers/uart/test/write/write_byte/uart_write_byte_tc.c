#include "uart_write_byte_tc.h"

const uart_write_byte_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-UART-WRITE-BYTE-001: Write minimum byte value (0x0)",
        .input =
        {
            .input_byte = 0x0
        },
        .expected =
        {
            .output_byte        = 0x0,
            .nb_call_mmio_write = 1U,
            .uart_addr          = 0x09000000U
        }
    },
    [1] =
    {
        .name  = "TC-UART-WRITE-BYTE-002: Write maximum byte value (0x7F)",
        .input =
        {
            .input_byte = 0x7F
        },
        .expected =
        {
            .output_byte        = 0x7F,
            .nb_call_mmio_write = 1U,
            .uart_addr          = 0x09000000U
        }
    },
    [2] =
    {
        .name  = "TC-UART-WRITE-BYTE-003: Write arbitrary byte value (0xA5)",
        .input =
        {
            .input_byte = 0xA5
        },
        .expected =
        {
            .output_byte        = 0xA5,
            .nb_call_mmio_write = 1U,
            .uart_addr          = 0x09000000U
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "uart_write_byte",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
