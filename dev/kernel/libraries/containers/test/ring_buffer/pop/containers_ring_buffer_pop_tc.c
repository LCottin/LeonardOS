#include "containers_ring_buffer_pop_tc.h"

const containers_ring_buffer_pop_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-RB-POP-001: Pop from an empty buffer returns NULL_PTR",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U
        },
        .expected =
        {
            .returns_null = TRUE,
            .dest_offset  = 0U,
            .head         = 0U,
            .tail         = 0U,
            .size         = 0U
        }
    },
    [1] =
    {
        .name  = "TC-RB-POP-002: Pop the only element",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 1U,
            .head         = 1U,
            .tail         = 0U
        },
        .expected =
        {
            .returns_null = FALSE,
            .dest_offset  = 0U,
            .head         = 1U,
            .tail         = 1U,
            .size         = 0U
        }
    },
    [2] =
    {
        .name  = "TC-RB-POP-003: Pop with tail mid-range",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 2U,
            .head         = 3U,
            .tail         = 1U
        },
        .expected =
        {
            .returns_null = FALSE,
            .dest_offset  = 1U,
            .head         = 3U,
            .tail         = 2U,
            .size         = 1U
        }
    },
    [3] =
    {
        .name  = "TC-RB-POP-004: Pop causes tail to wrap around",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 1U,
            .head         = 0U,
            .tail         = 3U
        },
        .expected =
        {
            .returns_null = FALSE,
            .dest_offset  = 3U,
            .head         = 0U,
            .tail         = 0U,
            .size         = 0U
        }
    },
    [4] =
    {
        .name  = "TC-RB-POP-005: Pop from a full buffer",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 4U,
            .head         = 0U,
            .tail         = 0U
        },
        .expected =
        {
            .returns_null = FALSE,
            .dest_offset  = 0U,
            .head         = 0U,
            .tail         = 1U,
            .size         = 3U
        }
    },
    [5] =
    {
        .name  = "TC-RB-POP-006: Multi-byte elements: returned pointer offset must use element_size",
        .input =
        {
            .capacity     = 3U,
            .element_size = 4U,
            .size         = 1U,
            .head         = 1U,
            .tail         = 0U
        },
        .expected =
        {
            .returns_null = FALSE,
            .dest_offset  = 0U,
            .head         = 1U,
            .tail         = 1U,
            .size         = 0U
        }
    },
    [6] =
    {
        .name  = "TC-RB-POP-007: Single-slot buffer (capacity 1)",
        .input =
        {
            .capacity     = 1U,
            .element_size = 2U,
            .size         = 1U,
            .head         = 0U,
            .tail         = 0U
        },
        .expected =
        {
            .returns_null = FALSE,
            .dest_offset  = 0U,
            .head         = 0U,
            .tail         = 0U,
            .size         = 0U
        }
    },
    [7] =
    {
        .name  = "TC-RB-POP-008: Empty buffer with stale non-zero head/tail must still report",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 0U,
            .head         = 2U,
            .tail         = 2U
        },
        .expected =
        {
            .returns_null = TRUE,
            .dest_offset  = 0U,
            .head         = 2U,
            .tail         = 2U,
            .size         = 0U
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "containers_ring_buffer_pop",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
