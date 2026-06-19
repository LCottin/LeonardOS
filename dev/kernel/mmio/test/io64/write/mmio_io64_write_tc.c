#include "mmio_io64_write_tc.h"

const mmio_io64_write_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-IO64_WRITE-001: Write 0x0",
        .input =
        {
            .reg_value       = 0x0U,
            .init_byte       = 0xFFFFFFFFFFFFFFFFLLU
        },
        .expected =
        {
            .expected_value  = 0x0U,
        }
    },
    [1] =
    {
        .name  = "TC-IO64_WRITE-002: Write 0xFFFFFFFFFFFFFFFF",
        .input =
        {
            .reg_value       = 0xFFFFFFFFFFFFFFFFULL,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xFFFFFFFFFFFFFFFFULL,
        }
    },
    [2] =
    {
        .name  = "TC-IO64_WRITE-003: Write 0x1 (only LSB)",
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
        .name  = "TC-IO64_WRITE-004: Write 0x8000000000000000 (only MSB)",
        .input =
        {
            .reg_value       = 0x8000000000000000ULL,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x8000000000000000ULL,
        }
    },
    [4] =
    {
        .name  = "TC-IO64_WRITE-005: Write 0xAAAAAAAAAAAAAAAA",
        .input =
        {
            .reg_value       = 0xAAAAAAAAAAAAAAAAULL,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0xAAAAAAAAAAAAAAAAULL,
        }
    },
    [5] =
    {
        .name  = "TC-IO64_WRITE-006: Write 0x5555555555555555",
        .input =
        {
            .reg_value       = 0x5555555555555555ULL,
            .init_byte       = 0x0U
        },
        .expected =
        {
            .expected_value  = 0x5555555555555555ULL,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "mmio_io64_write",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
