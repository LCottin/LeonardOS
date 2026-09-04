#include "containers_ring_buffer_is_empty_tc.h"

const containers_ring_buffer_is_empty_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-RB-IS-EMPTY-001: size = 0",
        .input =
        {
            .capacity     = 8U,
            .element_size = 1U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U
        },
        .expected =
        {
            .is_empty = TRUE
        }
    },
    [1] =
    {
        .name  = "TC-RB-IS-EMPTY-002: size = 1",
        .input =
        {
            .capacity     = 8U,
            .element_size = 1U,
            .size         = 1U,
            .head         = 1U,
            .tail         = 0U
        },
        .expected =
        {
            .is_empty = FALSE
        }
    },
    [2] =
    {
        .name  = "TC-RB-IS-EMPTY-003: size = capacity (full)",
        .input =
        {
            .capacity     = 8U,
            .element_size = 1U,
            .size         = 8U,
            .head         = 0U,
            .tail         = 0U
        },
        .expected =
        {
            .is_empty = FALSE
        }
    },
    [3] =
    {
        .name  = "TC-RB-IS-EMPTY-004: arbitrary non-zero size",
        .input =
        {
            .capacity     = 256U,
            .element_size = 4U,
            .size         = 250U,
            .head         = 12U,
            .tail         = 3U
        },
        .expected =
        {
            .is_empty = FALSE
        }
    },
    [4] =
    {
        .name  = "TC-RB-IS-EMPTY-005: result depends only on size, not on head/tail/capacity",
        .input =
        {
            .capacity     = 16U,
            .element_size = 2U,
            .size         = 0U,
            .head         = 9U,
            .tail         = 9U
        },
        .expected =
        {
            .is_empty = TRUE
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "containers_ring_buffer_is_empty",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
