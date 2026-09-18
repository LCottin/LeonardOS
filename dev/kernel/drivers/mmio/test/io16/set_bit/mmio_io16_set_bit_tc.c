#include "mmio_io16_set_bit_tc.h"

const mmio_io16_set_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO16_SET_BIT-001: Set bit 0 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {0U}
        },
        .expected =
        {
            .expected_result = 0x1U,
        }
    },
    [1] =
    {
        .name  = "TC-IO16_SET_BIT-002: Set bit 15 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {15U}
        },
        .expected =
        {
            .expected_result = 0x8000U,
        }
    },
    [2] =
    {
        .name  = "TC-IO16_SET_BIT-003: Set bit 7 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {7U}
        },
        .expected =
        {
            .expected_result = 0x80U,
        }
    },
    [3] =
    {
        .name  = "TC-IO16_SET_BIT-004: Set already-set bit",
        .input =
        {
            .init_byte          = 0x1U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {0U}
        },
        .expected =
        {
            .expected_result = 0x1U,
        }
    },
    [4] =
    {
        .name  = "TC-IO16_SET_BIT-005: Set bit 4 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {4U}
        },
        .expected =
        {
            .expected_result = 0x10U,
        }
    },
    [5] =
    {
        .name  = "TC-IO16_SET_BIT-006: Set bit 7 of 0xFF7F",
        .input =
        {
            .init_byte          = 0xFF7FU,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {7U}
        },
        .expected =
        {
            .expected_result = 0xFFFFU,
        }
    },
    [6] =
    {
        .name  = "TC-IO16_SET_BIT-007: Sequential set bit 2 and bit 11 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 2U,
            .bit_index_to_set   = {2U, 11U}
        },
        .expected =
        {
            .expected_result = 0x804U,
        }
    },
    [7] =
    {
        .name  = "TC-IO16_SET_BIT-008: Set same bit twice, idempotent",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 2U,
            .bit_index_to_set   = {3U, 3U}
        },
        .expected =
        {
            .expected_result = 0x8U,
        }
    },
    [8] =
    {
        .name  = "TC-IO16_SET_BIT-009: Set all 16 bits one by one of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = K_MMIO_IO16_SET_BIT_NB_BITS_MAX,
            .bit_index_to_set   = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U}
        },
        .expected =
        {
            .expected_result = 0xFFFFU,
        }
    },
    [9] =
    {
        .name  = "TC-IO16_SET_BIT-010: Invalid index 16, register unchanged",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {16U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [10] =
    {
        .name  = "TC-IO16_SET_BIT-011: Invalid index 255, register unchanged",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {255U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io16_set_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
