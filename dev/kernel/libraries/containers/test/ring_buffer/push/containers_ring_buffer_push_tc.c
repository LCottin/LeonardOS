#include "containers_ring_buffer_push_tc.h"

const containers_ring_buffer_push_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-RB-PUSH-001: Push into an empty buffer",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U,
            .elements     = { 0x11U }
        },
        .expected =
        {
            .head         = 1U,
            .tail         = 0U,
            .size         = 1U,
            .dest_offset  = 0U,
            .nb_call_copy = 1U,
            .copy_size    = 1U
        }
    },
    [1] =
    {
        .name  = "TC-RB-PUSH-002: Push into a partially filled buffer",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 2U,
            .head         = 2U,
            .tail         = 0U,
            .elements     = { 0x22U }
        },
        .expected =
        {
            .head         = 3U,
            .tail         = 0U,
            .size         = 3U,
            .dest_offset  = 2U,
            .nb_call_copy = 1U,
            .copy_size    = 1U
        }
    },
    [2] =
    {
        .name  = "TC-RB-PUSH-003: Push that fills the buffer for the first time",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 3U,
            .head         = 3U,
            .tail         = 0U,
            .elements     = { 0x33U }
        },
        .expected =
        {
            .head         = 0U,
            .tail         = 0U,
            .size         = 4U,
            .dest_offset  = 3U,
            .nb_call_copy = 1U,
            .copy_size    = 1U
        }
    },
    [3] =
    {
        .name  = "TC-RB-PUSH-004: Push into a full buffer overwrites the oldest elements",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 4U,
            .head         = 0U,
            .tail         = 0U,
            .elements     = { 0x44U }
        },
        .expected =
        {
            .head         = 1U,
            .tail         = 1U,
            .size         = 4U,
            .dest_offset  = 0U,
            .nb_call_copy = 1U,
            .copy_size    = 1U
        }
    },
    [4] =
    {
        .name  = "TC-RB-PUSH-005: Push into a full buffer where the tail wraps around",
        .input =
        {
            .capacity     = 4U,
            .element_size = 1U,
            .size         = 4U,
            .head         = 3U,
            .tail         = 3U,
            .elements     = { 0x55U }
        },
        .expected =
        {
            .head         = 0U,
            .tail         = 0U,
            .size         = 4U,
            .dest_offset  = 3U,
            .nb_call_copy = 1U,
            .copy_size    = 1U
        }
    },
    [5] =
    {
        .name  = "TC-RB-PUSH-006: Multi-byte elements: destination offset must use element_size",
        .input =
        {
            .capacity     = 3U,
            .element_size = 4U,
            .size         = 1U,
            .head         = 1U,
            .tail         = 0U,
            .elements     = { 0xDEU, 0xADU, 0xBEU, 0xEFU }
        },
        .expected =
        {
            .head         = 2U,
            .tail         = 0U,
            .size         = 2U,
            .dest_offset  = 4U,
            .nb_call_copy = 1U,
            .copy_size    = 4U
        }
    },
    [6] =
    {
        .name  = "TC-RB-PUSH-007: Single-slot buffer (capacity 1), pushing into it while empty",
        .input =
        {
            .capacity     = 1U,
            .element_size = 2U,
            .size         = 0U,
            .head         = 0U,
            .tail         = 0U,
            .elements     = { 0xAAU, 0xBBU }
        },
        .expected =
        {
            .head         = 0U,
            .tail         = 0U,
            .size         = 1U,
            .dest_offset  = 0U,
            .nb_call_copy = 1U,
            .copy_size    = 2U
        }
    },
    [7] =
    {
        .name  = "TC-RB-PUSH-008: Single-slot buffer (capacity 1), pushing into it while already full",
        .input =
        {
            .capacity     = 1U,
            .element_size = 2U,
            .size         = 1U,
            .head         = 0U,
            .tail         = 0U,
            .elements     = { 0xCCU, 0xDDU }
        },
        .expected =
        {
            .head         = 0U,
            .tail         = 0U,
            .size         = 1U,
            .dest_offset  = 0U,
            .nb_call_copy = 1U,
            .copy_size    = 2U
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "containers_ring_buffer_push",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
