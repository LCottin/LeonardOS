#include "mmio_io8_read_tc.h"

const mmio_io8_read_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO8_READ-001: Read 0x0",
        .input =
        {
            .init_byte       = 0xFFU,
            .reg_value       = 0x0U,
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO8_READ-002: Read 0xFF",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xFFU,
        },
        .expected =
        {
            .expected_value  = 0xFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO8_READ-003: Read 0x80 (only MSB set)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x80U,
        },
        .expected =
        {
            .expected_value  = 0x80U,
        }
    },
    [3] =
    {
        .name  = "TC-IO8_READ-004: Read 0x1 (only LSB set)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x1U,
        },
        .expected =
        {
            .expected_value  = 0x1U,
        }
    },
    [4] =
    {
        .name  = "TC-IO8_READ-005: Read 0xAA (alternating bits 10101010)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xAAU,
        },
        .expected =
        {
            .expected_value  = 0xAAU,
        }
    },
    [5] =
    {
        .name  = "TC-IO8_READ-006: Read 0x55 (alternating bits 01010101)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x55U,
        },
        .expected =
        {
            .expected_value  = 0x55U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io8_read",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
