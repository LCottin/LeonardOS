#include "console_ctx_init_tc.h"

const console_ctx_init_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-CONSOLE-CTX-INIT-001: Normal initialization registers the buffer and the RX interrupt exactly once",
        .input =
        {
            .call_count = 1U
        },
        .expected =
        {
            .expected_capacity      = 256U,
            .expected_element_size  = 1U,
            .expected_irq_nb        = 33U,
            .nb_call_rb_init        = 1U,
            .nb_call_irq_register   = 1U,
        }
    },
    [1] =
    {
        .name  = "TC-CONSOLE-CTX-INIT-002: Repeated initialization calls scale linearly",
        .input =
        {
            .call_count = 3U
        },
        .expected =
        {
            .expected_capacity      = 256U,
            .expected_element_size  = 1U,
            .expected_irq_nb        = 33U,
            .nb_call_rb_init        = 3U,
            .nb_call_irq_register   = 3U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "console_ctx_init",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
