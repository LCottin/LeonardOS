#include "memory_ops_utils_copy_tc.h"

const memory_ops_utils_copy_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-COPY-001: copies a short buffer correctly",
        .input =
        {
            .fill1_byte  = 0xFFU,
            .fill2_byte  = 0,
            .buf1_size   = 16U,
            .buf2_size   = 16U,
            .copy_size   = 8U,
            .src_offset  = 0U,
            .dest_offset = 0U,
        }
    },
    [1] =
    {
        .name  = "TC-COPY-002: zero-size copy leaves destination unchanged",
        .input =
        {
            .fill1_byte  = 0xFFU,
            .fill2_byte  = 0,
            .buf1_size   = 16U,
            .buf2_size   = 16U,
            .copy_size   = 0U,
            .src_offset  = 0U,
            .dest_offset = 0U,
        }
    },
    [2] =
    {
        .name  = "TC-COPY-003: copies size not multiple of 8 (tail path)",
        .input =
        {
            .fill1_byte  = 0xFFU,
            .fill2_byte  = 0,
            .buf1_size   = 16U,
            .buf2_size   = 16U,
            .copy_size   = 13U,
            .src_offset  = 0U,
            .dest_offset = 0U,
        }
    },
    [3] =
    {
        .name  = "TC-COPY-004: misaligned source (+1 byte offset)",
        .input =
        {
            .fill1_byte  = 0xFFU,
            .fill2_byte  = 0,
            .buf1_size   = 16U,
            .buf2_size   = 16U,
            .copy_size   = 13U,
            .src_offset  = 1U,
            .dest_offset = 0U,
        }
    },
    [4] =
    {
        .name  = "TC-COPY-005: misaligned destination (+1 byte offset)",
        .input =
        {
            .fill1_byte  = 0xFFU,
            .fill2_byte  = 0,
            .buf1_size   = 16U,
            .buf2_size   = 16U,
            .copy_size   = 13U,
            .src_offset  = 0U,
            .dest_offset = 1U,
        }
    },
    [5] =
    {
        .name  = "TC-COPY-006: single byte copy",
        .input =
        {
            .fill1_byte  = 0xA5U,
            .fill2_byte  = 0,
            .buf1_size   = 16U,
            .buf2_size   = 16U,
            .copy_size   = 1U,
            .src_offset  = 0U,
            .dest_offset = 0U,
        }
    },
    [6] =
    {
        .name  = "TC-COPY-007: large buffer copy",
        .input =
        {
            .fill1_byte  = 0x0U,
            .fill2_byte  = 0xFF,
            .buf1_size   = BUFFER_SIZE,
            .buf2_size   = BUFFER_SIZE,
            .copy_size   = BUFFER_SIZE,
            .src_offset  = 0U,
            .dest_offset = 0U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "memory_ops_utils_copy",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
