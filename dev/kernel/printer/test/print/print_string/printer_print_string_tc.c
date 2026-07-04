#include "printer_print_string_tc.h"
#include "spec_utils_krn.h"

const printer_print_string_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-PRINT-STRING-001 - Print empty string",
        .input =
        {
            .str = SPEC_UTILS_DECONST_STRING(""),
        },
        .output =
        {
            .nb_call_uart = 0U,
        }
    },
    [1] =
    {
        .name  = "TC-PRINT-STRING-002 - Print string with one character",
        .input =
        {
            .str = SPEC_UTILS_DECONST_STRING("A"),
        },
        .output =
        {
            .nb_call_uart = 1U,
        }
    },
    [2] =
    {
        .name  = "TC-PRINT-STRING-003 - Print string with multiple characters",
        .input =
        {
            .str = SPEC_UTILS_DECONST_STRING("Hello, World!"),
        },
        .output =
        {
            .nb_call_uart = 13U,
        }
    },
    [3] =
    {
        .name  = "TC-PRINT-STRING-004 - Print string with special characters",
        .input =
        {
            .str = SPEC_UTILS_DECONST_STRING("Line1\nLine2\tTabbed"),
        },
        .output =
        {
            .nb_call_uart = 18U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "printer_print_string",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
