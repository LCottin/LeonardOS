#include "mmio_io32_write_tc.h"

const mmio_io32_write_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO32_WRITE-001: Write 0x0",
        .input =
        {
            .reg_value       = 0x0U,
            .init_byte       = 0xFFFFFFFFU
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO32_WRITE-002: Write 0xFFFFFFFF",
        .input =
        {
            .reg_value       = 0xFFFFFFFFU,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xFFFFFFFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO32_WRITE-003: Write 0x1 (only LSB)",
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
        .name  = "TC-IO32_WRITE-004: Write 0x80000000 (only MSB)",
        .input =
        {
            .reg_value       = 0x80000000U,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x80000000U,
        }
    },
    [4] =
    {
        .name  = "TC-IO32_WRITE-005: Write 0xAAAAAAAA",
        .input =
        {
            .reg_value       = 0xAAAAAAAAU,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xAAAAAAAAU,
        }
    },
    [5] =
    {
        .name  = "TC-IO32_WRITE-006: Write 0x55555555",
        .input =
        {
            .reg_value       = 0x55555555U,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x55555555U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io32_write",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
