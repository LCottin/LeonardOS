#include "console_buffer_pop_tc.h"

const console_buffer_pop_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-CONSOLE-BUFFER-POP-001: Ring buffer empty -> returns '\\0' fallback",
        .input =
        {
            .rb_is_empty = TRUE,
            .popped_byte = 0x00
        },
        .expected =
        {
            .output_byte    = '\0',
            .nb_call_rb_pop = 1U
        }
    },
    [1] =
    {
        .name  = "TC-CONSOLE-BUFFER-POP-002: Ring buffer non-empty, typical printable character",
        .input =
        {
            .rb_is_empty = FALSE,
            .popped_byte = 'X'
        },
        .expected =
        {
            .output_byte    = 'X',
            .nb_call_rb_pop = 1U
        }
    },
    [2] =
    {
        .name  = "TC-CONSOLE-BUFFER-POP-003: Ring buffer non-empty but the popped byte itself is 0x00",
        .input =
        {
            .rb_is_empty = FALSE,
            .popped_byte = 0x00
        },
        .expected =
        {
            .output_byte    = '\0',
            .nb_call_rb_pop = 1U
        }
    },
    [3] =
    {
        .name  = "TC-CONSOLE-BUFFER-POP-004: Ring buffer non-empty, high-bit byte (0xFF)",
        .input =
        {
            .rb_is_empty = FALSE,
            .popped_byte = (char_t)0xFF
        },
        .expected =
        {
            .output_byte    = (char_t)0xFF,
            .nb_call_rb_pop = 1U
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "console_buffer_pop",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
