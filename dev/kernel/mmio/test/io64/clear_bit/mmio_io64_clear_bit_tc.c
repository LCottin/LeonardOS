#include "mmio_io64_clear_bit_tc.h"

const mmio_io64_clear_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO64_CLEAR_BIT-001: Clear bit 0 of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {0U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFFFFFEULL,
        }
    },
    [1] =
    {
        .name  = "TC-IO64_CLEAR_BIT-002: Clear bit 63 of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {63U}
        },
        .expected =
        {
            .expected_result = 0x7FFFFFFFFFFFFFFFULL,
        }
    },
    [2] =
    {
        .name  = "TC-IO64_CLEAR_BIT-003: Clear bit 15 of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {15U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFF7FFFULL,
        }
    },
    [3] =
    {
        .name  = "TC-IO64_CLEAR_BIT-004: Clear already-cleared bit",
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
        .name  = "TC-IO64_CLEAR_BIT-005: Clear bit 0 of 0x01",
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
        .name  = "TC-IO64_CLEAR_BIT-006: Clear bit 31 of 0x80000000",
        .input =
        {
            .init_value         = 0x80000000ULL,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {31U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [6] =
    {
        .name  = "TC-IO64_CLEAR_BIT-007: Sequential clears bit 21 and bit 48 of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {21U, 48U}
        },
        .expected =
        {
            .expected_result = 0xFFFEFFFFFFDFFFFFULL,
        }
    },
    [7] =
    {
        .name  = "TC-IO64_CLEAR_BIT-008: Clear same bit twice, idempotent",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = 2U,
            .bit_index_to_clear = {18U, 18U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFBFFFFULL,
        }
    },
    [8] =
    {
        .name  = "TC-IO64_CLEAR_BIT-009: Clear all 64 bits one by one of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = K_MMIO_IO64_CLEAR_BIT_NB_BITS_MAX,
            .bit_index_to_clear = {0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U,  8U,  9U, 10U, 11U, 12U, 13U, 14U, 15U,
                                  16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U,
                                  32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U,
                                  48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [9] =
    {
        .name  = "TC-IO64_CLEAR_BIT-010: Invalid index 64, register unchanged",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {64U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFFFFFFULL,
        }
    },
    [10] =
    {
        .name  = "TC-IO64_CLEAR_BIT-011: Invalid index 255, register unchanged",
        .input =
        {
            .init_value         = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_clears   = 1U,
            .bit_index_to_clear = {255U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFFFFFFULL,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io64_clear_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
