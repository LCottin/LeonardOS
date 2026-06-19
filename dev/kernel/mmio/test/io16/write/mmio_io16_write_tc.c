#include "mmio_io16_write_tc.h"

const mmio_io16_write_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO16_WRITE-001: Write 0x0",
        .input =
        {
            .reg_value       = 0x0U,
            .init_byte       = 0xFFFFU
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO16_WRITE-002: Write 0xFFFF",
        .input =
        {
            .reg_value       = 0xFFFFU,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xFFFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO16_WRITE-003: Write 0x1 (only LSB)",
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
        .name  = "TC-IO16_WRITE-004: Write 0x8000 (only MSB)",
        .input =
        {
            .reg_value       = 0x8000U,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x8000U,
        }
    },
    [4] =
    {
        .name  = "TC-IO16_WRITE-005: Write 0xAAAA",
        .input =
        {
            .reg_value       = 0xAAAAU,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xAAAAU,
        }
    },
    [5] =
    {
        .name  = "TC-IO16_WRITE-006: Write 0x5555",
        .input =
        {
            .reg_value       = 0x5555U,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x5555U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io16_write",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
