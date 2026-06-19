#include "mmio_io8_write_tc.h"

const mmio_io8_write_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO8_WRITE-001: Write 0x0",
        .input =
        {
            .reg_value       = 0x0U,
            .init_byte       = 0xFFU
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO8_WRITE-002: Write 0xFF",
        .input =
        {
            .reg_value       = 0xFFU,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO8_WRITE-003: Write 0x1 (only LSB)",
        .input =
        {
            .reg_value       = 0x1U,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x1U,
        }
    },
    [3] =
    {
        .name  = "TC-IO8_WRITE-004: Write 0x80 (only MSB)",
        .input =
        {
            .reg_value       = 0x8U,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x8U,
        }
    },
    [4] =
    {
        .name  = "TC-IO8_WRITE-005: Write 0xAA",
        .input =
        {
            .reg_value       = 0xAAU,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xAAU,
        }
    },
    [5] =
    {
        .name  = "TC-IO8_WRITE-006: Write 0x55",
        .input =
        {
            .reg_value       = 0x55U,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x55U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io8_write",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
