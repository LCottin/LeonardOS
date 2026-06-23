#include "mmio_io16_toggle_bit_tc.h"

const mmio_io16_toggle_bit_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-001: Toggle bit 0 of 0x0",
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
        .name  = "TC-IO16_TOGGLE_BIT-002: Toggle bit 7 of 0x0",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {7U}
        },
        .expected =
        {
            .expected_result = 0x80U,
        }
    },
    [2] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-003: Toggle bit 15 of 0x0",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {15U}
        },
        .expected =
        {
            .expected_result = 0x8000U,
        }
    },
    [3] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-004: Toggle bit 3 of 0xFFFF",
        .input =
        {
            .init_byte           = 0xFFFFU,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {3U}
        },
        .expected =
        {
            .expected_result = 0xFFF7U,
        }
    },
    [4] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-005: Toggle bit 4 of 0xFFFF",
        .input =
        {
            .init_byte           = 0xFFFFU,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {4U}
        },
        .expected =
        {
            .expected_result = 0xFFEFU,
        }
    },
    [5] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-006: Toggle bit 15 of 0xFFFF",
        .input =
        {
            .init_byte           = 0xFFFFU,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {15U}
        },
        .expected =
        {
            .expected_result = 0x7FFFU,
        }
    },
    [6] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-007: Sequential toggle bit 2 and bit 11 of 0x0",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 2U,
            .bit_index_to_toggle = {2U, 11U}
        },
        .expected =
        {
            .expected_result = 0x804U,
        }
    },
    [7] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-008: Toggle same bit twice, idempotent",
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
        .name  = "TC-IO16_TOGGLE_BIT-009: Toggle all 16 bits one by one of 0xA5A5",
        .input =
        {
            .init_byte           = 0xA5A5,
            .number_of_toggles   = K_MMIO_IO16_TOGGLE_BIT_NB_BITS_MAX,
            .bit_index_to_toggle = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U, 12U, 13U, 14U, 15U}
        },
        .expected =
        {
            .expected_result = 0x5A5A,
        }
    },
    [9] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-010: Invalid index 16, register unchanged",
        .input =
        {
            .init_byte           = 0x0U,
            .number_of_toggles   = 1U,
            .bit_index_to_toggle = {16U}
        },
        .expected =
        {
            .expected_result = 0x0U,
        }
    },
    [10] =
    {
        .name  = "TC-IO16_TOGGLE_BIT-011: Invalid index 255, register unchanged",
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
    .suite_name = "mmio_io16_toggle_bit",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
