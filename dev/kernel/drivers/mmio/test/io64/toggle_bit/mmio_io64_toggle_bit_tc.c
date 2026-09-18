#include "mmio_io64_toggle_bit_tc.h"

const mmio_io64_toggle_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-001: Toggle bit 0 of 0x0",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {0U}
        },
        .expected =
        {
            .expected_result = 0x1U,
        }
    },
    [1] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-002: Toggle bit 31 of 0x0",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {31U}
        },
        .expected =
        {
            .expected_result = 0x80000000ULL,
        }
    },
    [2] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-003: Toggle bit 63 of 0x0",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {63U}
        },
        .expected =
        {
            .expected_result = 0x8000000000000000ULL,
        }
    },
    [3] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-004: Toggle bit 3 of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_byte           = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {3U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFFFFF7ULL,
        }
    },
    [4] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-005: Toggle bit 4 of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_byte           = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {4U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFFFFFFFFEFULL,
        }
    },
    [5] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-006: Toggle bit 31 of 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_byte           = 0xFFFFFFFFFFFFFFFFULL,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {31U}
        },
        .expected =
        {
            .expected_result = 0xFFFFFFFF7FFFFFFFULL,
        }
    },
    [6] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-007: Sequential toggle bit 21 and bit 48 of 0x0",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 2U,
            .bit_index_to_toggle = {21U, 48U}
        },
        .expected =
        {
            .expected_result = 0x1000000200000ULL,
        }
    },
    [7] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-008: Toggle same bit twice, idempotent",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 2U,
            .bit_index_to_toggle = {3U, 3U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [8] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-009: Toggle all 64 bits one by one of 0xA5A5A5A5A5A5A5A5",
        .input =
        {
            .init_byte           = 0xA5A5A5A5A5A5A5A5ULL,
            .number_of_toggles   = K_MMIO_IO64_TOGGLE_BIT_NB_BITS_MAX,
            .bit_index_to_toggle = {0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U,  8U,  9U, 10U, 11U, 12U, 13U, 14U, 15U,
                                   16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U,
                                   32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U, 40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U,
                                   48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U, 56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U}
        },
        .expected =
        {
            .expected_result = 0x5A5A5A5A5A5A5A5AULL,
        }
    },
    [9] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-010: Invalid index 64, register unchanged",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {64U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [10] =
    {
        .name  = "TC-IO64_TOGGLE_BIT-011: Invalid index 255, register unchanged",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {255U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io64_toggle_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
