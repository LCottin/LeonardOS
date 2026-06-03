#include "memory_ops_utils_set_tc.h"

const memory_ops_utils_set_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-SET-001: set buffer to 0x0 correctly",
        .input =
        {
            .fill_byte  = 0xFF,
            .data_value = 0x0,
            .buf_size   = 16U,
            .buf_offset = 0,
        }
    },
    [1] =
    {
        .name  = "TC-SET-002: set buffer to 0xFF correctly",
        .input =
        {
            .fill_byte  = 0x0,
            .data_value = 0xFF,
            .buf_size   = 16U,
            .buf_offset = 0,
        }
    },
    [2] =
    {
        .name  = "TC-SET-003: set buffer to 0xA5 correctly",
        .input =
        {
            .fill_byte  = 0xFF,
            .data_value = 0xA5,
            .buf_size   = 16U,
            .buf_offset = 0,
        }
    },
    [3] =
    {
        .name  = "TC-SET-004: zero-size leave destination unchanged",
        .input =
        {
            .fill_byte  = 0xFF,
            .data_value = 0x0,
            .buf_size   = 0U,
            .buf_offset = 0,
        }
    },
    [4] =
    {
        .name  = "TC-SET-005: int32 0x12345678 stores only low byte 0x78",
        .input =
        {
            .fill_byte  = 0xFF,
            .data_value = 0x12345678,
            .buf_size   = 16U,
            .buf_offset = 0,
        }
    },
    [5] =
    {
        .name  = "TC-SET-006: negative value -1 stores 0xFF",
        .input =
        {
            .fill_byte  = 0x0,
            .data_value = -1,
            .buf_size   = 16U,
            .buf_offset = 0,
        }
    },
    [6] =
    {
        .name  = "TC-SET-007: single-byte copy",
        .input =
        {
            .fill_byte  = 0x0,
            .data_value = 0xFF,
            .buf_size   = 1U,
            .buf_offset = 0,
        }
    },
    [7] =
    {
        .name  = "TC-SET-008: size not aligned to 8 bytes (7 bytes)",
        .input =
        {
            .fill_byte  = 0x0,
            .data_value = 0xFF,
            .buf_size   = 7U,
            .buf_offset = 0,
        }
    },
    [8] =
    {
        .name  = "TC-SET-009: size not aligned to 8 bytes (9 bytes)",
        .input =
        {
            .fill_byte  = 0x0,
            .data_value = 0xFF,
            .buf_size   = 9U,
            .buf_offset = 0,
        }
    },
    [9] =
    {
        .name  = "TC-SET-010: large buffer copy",
        .input =
        {
            .fill_byte  = 0x0,
            .data_value = 0xFF,
            .buf_size   = BUFFER_SIZE,
            .buf_offset = 0,
        }
    },
    [10] =
    {
        .name  = "TC-SET-011: misaligned source (+1 byte offset)",
        .input =
        {
            .fill_byte  = 0x0,
            .data_value = 0xFF,
            .buf_size   = BUFFER_SIZE,
            .buf_offset = 1,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "memory_ops_utils_set",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
