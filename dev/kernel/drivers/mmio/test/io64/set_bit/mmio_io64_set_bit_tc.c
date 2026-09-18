#include "mmio_io64_set_bit_tc.h"

const mmio_io64_set_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO64_SET_BIT-001: Set bit 0 of 0x0",
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
        .name  = "TC-IO64_SET_BIT-002: Set bit 63 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {63U}
        },
        .expected =
        {
            .expected_result = 0x8000000000000000ULL,
        }
    },
    [2] =
    {
        .name  = "TC-IO64_SET_BIT-003: Set bit 32 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {32U}
        },
        .expected =
        {
            .expected_result = 0x100000000ULL,
        }
    },
    [3] =
    {
        .name  = "TC-IO64_SET_BIT-004: Set already-set bit",
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
        .name  = "TC-IO64_SET_BIT-005: Set bit 4 of 0x0",
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
        .name  = "TC-IO64_SET_BIT-006: Set bit 7 of 0xFFFFFFFFFFFFFF7F",
        .input =
        {
            .init_byte          = 0xFFFFFFFFFFFFFF7FULL,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {7U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFFFFFFULL,
        }
    },
    [6] =
    {
        .name  = "TC-IO64_SET_BIT-007: Sequential set bit 21 and bit 48 of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 2U,
            .bit_index_to_set   = {21U, 48U}
        },
        .expected =
        {
            .expected_result = 0x1000000200000ULL,
        }
    },
    [7] =
    {
        .name  = "TC-IO64_SET_BIT-008: Set same bit twice, idempotent",
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
        .name  = "TC-IO64_SET_BIT-009: Set all 64 bits one by one of 0x0",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = K_MMIO_IO64_SET_BIT_NB_BITS_MAX,
            .bit_index_to_set   = {0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U,  8U,  9U, 10U, 11U, 12U, 13U, 14U, 15U,
                                  16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U,
                                  32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U,
                                  48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFFFFFFULL,
        }
    },
    [9] =
    {
        .name  = "TC-IO64_SET_BIT-010: Invalid index 64, register unchanged",
        .input =
        {
            .init_byte          = 0x0U,
            .number_of_sets     = 1U,
            .bit_index_to_set   = {64U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [10] =
    {
        .name  = "TC-IO64_SET_BIT-011: Invalid index 255, register unchanged",
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
    .suite_name = "mmio_io64_set_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
