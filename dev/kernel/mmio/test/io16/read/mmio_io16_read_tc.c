#include "mmio_io16_read_tc.h"

const mmio_io16_read_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO16_READ-001: Read 0x0",
        .input =
        {
            .init_byte       = 0xFFFFU,
            .reg_value       = 0x0U,
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO16_READ-002: Read 0xFFFF",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xFFFFU,
        },
        .expected =
        {
            .expected_value  = 0xFFFFU,
        }
    },
    [2] =
    {
        .name  = "TC-IO16_READ-003: Read 0x8000 (only MSB set)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x8000U,
        },
        .expected =
        {
            .expected_value  = 0x8000U,
        }
    },
    [3] =
    {
        .name  = "TC-IO16_READ-004: Read 0x1 (only LSB set)",
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
        .name  = "TC-IO16_READ-005: Read 0xAAAA (alternating bits 1010101010101010)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xAAAAU,
        },
        .expected =
        {
            .expected_value  = 0xAAAAU,
        }
    },
    [5] =
    {
        .name  = "TC-IO16_READ-006: Read 0x5555 (alternating bits 0101010101010101)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x5555U,
        },
        .expected =
        {
            .expected_value  = 0x5555U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io16_read",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
