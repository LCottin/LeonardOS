#include "console_irq_rx_tc.h"

const console_irq_rx_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-CONSOLE-IRQ-RX-001: Read the NULL byte and forward it to the console buffer",
        .input =
        {
            .input_byte = 0x00
        },
        .expected =
        {
            .nb_call_uart_read   = 1U,
            .nb_call_buffer_push = 1U,
            .pushed_byte         = 0x00
        }
    },
    [1] =
    {
        .name  = "TC-CONSOLE-IRQ-RX-002: Read a typical printable character and forward it",
        .input =
        {
            .input_byte = 'A'
        },
        .expected =
        {
            .nb_call_uart_read   = 1U,
            .nb_call_buffer_push = 1U,
            .pushed_byte         = 'A'
        }
    },
    [2] =
    {
        .name  = "TC-CONSOLE-IRQ-RX-003: Read the maximum positive char value and forward it",
        .input =
        {
            .input_byte = 0x7F
        },
        .expected =
        {
            .nb_call_uart_read   = 1U,
            .nb_call_buffer_push = 1U,
            .pushed_byte         = 0x7F
        }
    },
    [3] =
    {
        .name  = "TC-CONSOLE-IRQ-RX-004: Read a high-bit byte and forward it",
        .input =
        {
            .input_byte = (char_t)0xFF
        },
        .expected =
        {
            .nb_call_uart_read   = 1U,
            .nb_call_buffer_push = 1U,
            .pushed_byte         = (char_t)0xFF
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "console_irq_rx",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
