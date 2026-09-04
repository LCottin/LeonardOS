#include "mmio_io64_read_tc.h"

const mmio_io64_read_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO64_READ-001: Read 0x0",
        .input =
        {
            .init_byte       = 0xFFFFFFFFFFFFFFFFULL,
            .reg_value       = 0x0U,
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO64_READ-002: Read 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xFFFFFFFFFFFFFFFFULL,
        },
        .expected =
        {
            .expected_value  = 0xFFFFFFFFFFFFFFFFULL,
        }
    },
    [2] =
    {
        .name  = "TC-IO64_READ-003: Read 0x8000000000000000 (only MSB set)",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x8000000000000000ULL,
        },
        .expected =
        {
            .expected_value  = 0x8000000000000000ULL,
        }
    },
    [3] =
    {
        .name  = "TC-IO64_READ-004: Read 0x1 (only LSB set)",
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
        .name  = "TC-IO64_READ-005: Read 0xAAAAAAAAAAAAAAAA",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0xAAAAAAAAAAAAAAAAULL,
        },
        .expected =
        {
            .expected_value  = 0xAAAAAAAAAAAAAAAAULL,
        }
    },
    [5] =
    {
        .name  = "TC-IO64_READ-006: Read 0x5555555555555555",
        .input =
        {
            .init_byte       = 0x0U,
            .reg_value       = 0x5555555555555555ULL,
        },
        .expected =
        {
            .expected_value  = 0x5555555555555555ULL,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io64_read",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
