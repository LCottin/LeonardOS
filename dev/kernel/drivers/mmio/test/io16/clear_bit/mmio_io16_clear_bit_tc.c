#include "mmio_io16_clear_bit_tc.h"

const mmio_io16_clear_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO16_CLEAR_BIT-001: Clear bit 0 of 0xFFFF",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {0U}
        },
        .expected =
        {
            .expected_result = 0xFFFEU,
        }
    },
    [1] =
    {
        .name  = "TC-IO16_CLEAR_BIT-002: Clear bit 15 of 0xFFFF",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {15U}
        },
        .expected =
        {
            .expected_result = 0x7FFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO16_CLEAR_BIT-003: Clear bit 7 of 0xFFFF",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {7U}
        },
        .expected =
        {
            .expected_result = 0xFF7FU,
        }
    },
    [3] =
    {
        .name  = "TC-IO16_CLEAR_BIT-004: Clear already-cleared bit",
        .input =
        {
            .init_value         = 0x0U,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {3U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [4] =
    {
        .name  = "TC-IO16_CLEAR_BIT-005: Clear bit 0 of 0x01",
        .input =
        {
            .init_value         = 0x1U,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {0U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [5] =
    {
        .name  = "TC-IO16_CLEAR_BIT-006: Clear bit 7 of 0x80",
        .input =
        {
            .init_value         = 0x80U,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {7U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [6] =
    {
        .name  = "TC-IO16_CLEAR_BIT-007: Sequential clears bit 2 and bit 11 of 0xFFFF",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {2U, 11U}
        },
        .expected =
        {
            .expected_result = 0xF7FBU,
        }
    },
    [7] =
    {
        .name  = "TC-IO16_CLEAR_BIT-008: Clear same bit twice, idempotent",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {11U, 11U}
        },
        .expected =
        {
            .expected_result = 0xF7FFU,
        }
    },
    [8] =
    {
        .name  = "TC-IO16_CLEAR_BIT-009: Clear all 16 bits one by one of 0xFFFF",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = K_MMIO_IO16_CLEAR_BIT_NB_BITS_MAX,
            .bit_index_to_clear = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [9] =
    {
        .name  = "TC-IO16_CLEAR_BIT-010: Invalid index 16, register unchanged",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {16U}
        },
        .expected =
        {
            .expected_result = 0xFFFFU,
        }
    },
    [10] =
    {
        .name  = "TC-IO16_CLEAR_BIT-011: Invalid index 255, register unchanged",
        .input =
        {
            .init_value         = 0xFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {255U}
        },
        .expected =
        {
            .expected_result = 0xFFFFU,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io16_clear_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
