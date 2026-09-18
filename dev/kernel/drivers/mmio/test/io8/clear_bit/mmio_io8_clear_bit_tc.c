#include "mmio_io8_clear_bit_tc.h"

const mmio_io8_clear_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO8_CLEAR_BIT-001: Clear bit 0 of 0xFF",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {0U}
        },
        .expected =
        {
            .expected_result = 0xFEU,
        }
    },
    [1] =
    {
        .name  = "TC-IO8_CLEAR_BIT-002: Clear bit 7 of 0xFF",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {7U}
        },
        .expected =
        {
            .expected_result = 0x7FU,
        }
    },
    [2] =
    {
        .name  = "TC-IO8_CLEAR_BIT-003: Clear bit 3 of 0xFF",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {3U}
        },
        .expected =
        {
            .expected_result = 0xF7U,
        }
    },
    [3] =
    {
        .name  = "TC-IO8_CLEAR_BIT-004: Clear already-cleared bit",
        .input =
        {
            .init_byte          = 0x0U,
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
        .name  = "TC-IO8_CLEAR_BIT-005: Clear bit 0 of 0x01",
        .input =
        {
            .init_byte          = 0x1U,
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
        .name  = "TC-IO8_CLEAR_BIT-006: Clear bit 7 of 0x80",
        .input =
        {
            .init_byte          = 0x80U,
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
        .name  = "TC-IO8_CLEAR_BIT-007: Sequential clears bit 2 and bit 5 of 0xFF",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {2U, 5U}
        },
        .expected =
        {
            .expected_result = 0xDBU,
        }
    },
    [7] =
    {
        .name  = "TC-IO8_CLEAR_BIT-008: Clear same bit twice, idempotent",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {3U, 3U}
        },
        .expected =
        {
            .expected_result = 0xF7U,
        }
    },
    [8] =
    {
        .name  = "TC-IO8_CLEAR_BIT-009: Clear all 8 bits one by one of 0xFF",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = K_MMIO_IO8_CLEAR_BIT_NB_BITS_MAX,
            .bit_index_to_clear = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [9] =
    {
        .name  = "TC-IO8_CLEAR_BIT-010: Invalid index 8, register unchanged",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {8U}
        },
        .expected =
        {
            .expected_result = 0xFFU,
        }
    },
    [10] =
    {
        .name  = "TC-IO8_CLEAR_BIT-011: Invalid index 255, register unchanged",
        .input =
        {
            .init_byte          = 0xFFU,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {255U}
        },
        .expected =
        {
            .expected_result = 0xFFU,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io8_clear_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
