#include "mmio_io32_clear_bit_tc.h"

const mmio_io32_clear_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO32_CLEAR_BIT-001: Clear bit 0 of 0xFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {0U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFEU,
        }
    },
    [1] =
    {
        .name  = "TC-IO32_CLEAR_BIT-002: Clear bit 31 of 0xFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {31U}
        },
        .expected =
        {
            .expected_result = 0x7FFFFFFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO32_CLEAR_BIT-003: Clear bit 15 of 0xFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {15U}
        },
        .expected =
        {
            .expected_result = 0xFFFF7FFFU,
        }
    },
    [3] =
    {
        .name  = "TC-IO32_CLEAR_BIT-004: Clear already-cleared bit",
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
        .name  = "TC-IO32_CLEAR_BIT-005: Clear bit 0 of 0x01",
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
        .name  = "TC-IO32_CLEAR_BIT-006: Clear bit 15 of 0x8000",
        .input =
        {
            .init_value         = 0x8000U,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {15U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [6] =
    {
        .name  = "TC-IO32_CLEAR_BIT-007: Sequential clears bit 11 and bit 18 of 0xFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {11U, 18U}
        },
        .expected =
        {
            .expected_result = 0xFFFBF7FFU,
        }
    },
    [7] =
    {
        .name  = "TC-IO32_CLEAR_BIT-008: Clear same bit twice, idempotent",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {18U, 18U}
        },
        .expected =
        {
            .expected_result = 0xFFFBFFFFU,
        }
    },
    [8] =
    {
        .name  = "TC-IO32_CLEAR_BIT-009: Clear all 32 bits one by one of 0xFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = K_MMIO_IO32_CLEAR_BIT_NB_BITS_MAX,
            .bit_index_to_clear = {0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U,  8U,  9U, 10U, 11U, 12U, 13U, 14U, 15U,
                                  16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [9] =
    {
        .name  = "TC-IO32_CLEAR_BIT-010: Invalid index 32, register unchanged",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {32U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFU,
        }
    },
    [10] =
    {
        .name  = "TC-IO32_CLEAR_BIT-011: Invalid index 255, register unchanged",
        .input =
        {
            .init_value         = 0xFFFFFFFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {255U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFU,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io32_clear_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
