#include "mmio_io32_read_tc.h"

const mmio_io32_read_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO32_READ-001: Read 0x0",
        .input =
        {
            .init_byte       = 0xFFFFFFFFU,
            .reg_value       = 0x0U,
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO32_READ-002: Read 0xFFFFFFFF",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xFFFFFFFFU,
        },
        .expected =
        {
            .expected_value  = 0xFFFFFFFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO32_READ-003: Read 0x80000000 (only MSB set)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x80000000U,
        },
        .expected =
        {
            .expected_value  = 0x80000000U,
        }
    },
    [3] =
    {
        .name  = "TC-IO32_READ-004: Read 0x1 (only LSB set)",
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
        .name  = "TC-IO32_READ-005: Read 0xAAAAAAAA (alternating bits 10101010101010101010101010101010)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xAAAAAAAAU,
        },
        .expected =
        {
            .expected_value  = 0xAAAAAAAAU,
        }
    },
    [5] =
    {
        .name  = "TC-IO32_READ-006: Read 0x55555555 (alternating bits 01010101010101010101010101010101)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x55555555U,
        },
        .expected =
        {
            .expected_value  = 0x55555555U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io32_read",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
