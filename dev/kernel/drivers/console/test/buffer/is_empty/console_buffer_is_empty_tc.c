#include "console_buffer_is_empty_tc.h"

const console_buffer_is_empty_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-CONSOLE-BUFFER-IS-EMPTY-001: Ring buffer reports empty",
        .input =
        {
            .rb_is_empty = TRUE
        },
        .expected =
        {
            .is_empty            = TRUE,
            .nb_call_rb_is_empty = 1U
        }
    },
    [1] =
    {
        .name  = "TC-CONSOLE-BUFFER-IS-EMPTY-002: Ring buffer reports non-empty",
        .input =
        {
            .rb_is_empty = FALSE
        },
        .expected =
        {
            .is_empty            = FALSE,
            .nb_call_rb_is_empty = 1U
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "console_buffer_is_empty",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
