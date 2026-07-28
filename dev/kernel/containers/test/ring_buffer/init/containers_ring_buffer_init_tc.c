#include "containers_ring_buffer_init_tc.h"

const containers_ring_buffer_init_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-RB-INIT-001: Typical capacity/element_size, clean starting state",
        .input =
        {
            .capacity     = 8U,
            .element_size = 4U,
            .dirty_size   = 0U,
            .dirty_head   = 0U,
            .dirty_tail   = 0U
        },
        .expected =
        {
            .capacity     = 8U,
            .element_size = 4U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U
        }
    },
    [1] =
    {
        .name  = "TC-RB-INIT-002: Minimum capacity and element_size",
        .input =
        {
            .capacity     = 1U,
            .element_size = 1U,
            .dirty_size   = 0U,
            .dirty_head   = 0U,
            .dirty_tail   = 0U
        },
        .expected =
        {
            .capacity     = 1U,
            .element_size = 1U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U
        }
    },
    [2] =
    {
        .name  = "TC-RB-INIT-003: Large capacity/element_size values",
        .input =
        {
            .capacity     = 256U,
            .element_size = 16U,
            .dirty_size   = 0U,
            .dirty_head   = 0U,
            .dirty_tail   = 0U
        },
        .expected =
        {
            .capacity     = 256U,
            .element_size = 16U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U
        }
    },
    [3] =
    {
        .name  = "TC-RB-INIT-004: init() must reset size/head/tail",
        .input =
        {
            .capacity     = 8U,
            .element_size = 4U,
            .dirty_size   = 99U,
            .dirty_head   = 5U,
            .dirty_tail   = 3U
        },
        .expected =
        {
            .capacity     = 8U,
            .element_size = 4U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U
        }
    },
    [4] =
    {
        .name  = "TC-RB-INIT-005: Re-init must overwrite a previously-used",
        .input =
        {
            .capacity     = 20U,
            .element_size = 8U,
            .dirty_size   = 5U,
            .dirty_head   = 7U,
            .dirty_tail   = 2U
        },
        .expected =
        {
            .capacity     = 20U,
            .element_size = 8U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "containers_ring_buffer_init",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
