#include "console_buffer_push_tc.h"

const console_buffer_push_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-CONSOLE-BUFFER-PUSH-001: Push the NULL byte",
        .input =
        {
            .input_byte = 0x00
        },
        .expected =
        {
            .output_byte     = 0x00,
            .nb_call_rb_push = 1U
        }
    },
    [1] =
    {
        .name  = "TC-CONSOLE-BUFFER-PUSH-002: Push a typical printable character",
        .input =
        {
            .input_byte = 'A'
        },
        .expected =
        {
            .output_byte     = 'A',
            .nb_call_rb_push = 1U
        }
    },
    [2] =
    {
        .name  = "TC-CONSOLE-BUFFER-PUSH-003: Push the maximum positive char value",
        .input =
        {
            .input_byte = 0x7F
        },
        .expected =
        {
            .output_byte     = 0x7F,
            .nb_call_rb_push = 1U
        }
    },
    [3] =
    {
        .name  = "TC-CONSOLE-BUFFER-PUSH-004: Push a high-bit byte",
        .input =
        {
            .input_byte = (char_t)0xFF
        },
        .expected =
        {
            .output_byte     = (char_t)0xFF,
            .nb_call_rb_push = 1U
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "console_buffer_push",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
