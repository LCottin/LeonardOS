#include "memory_ops_utils_cmp_tc.h"

const memory_ops_utils_cmp_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-CMP-001: identical buffers return 0",
        .input =
        {
            .fill1_byte = 0xA5U,
            .fill2_byte = 0xA5U,
            .buf1_size  = 16U,
            .buf2_size  = 16U,
            .cmp_size   = 16U,
        },
        .expected =
        {
            .comparison_result = 0
        }
    },
    [1] =
    {
        .name  = "TC-CMP-002: single equal byte returns 0",
        .input =
        {
            .fill1_byte = 0x5AU,
            .fill2_byte = 0x5AU,
            .buf1_size  = 1U,
            .buf2_size  = 1U,
            .cmp_size   = 1U,
        },
        .expected =
        {
            .comparison_result = 0
        }
    },
    [2] =
    {
        .name  = "TC-CMP-003: zero-size compare always returns 0",
        .input =
        {
            .fill1_byte = 0xA5U,
            .fill2_byte = 0xA5U,
            .buf1_size  = 0U,
            .buf2_size  = 0U,
            .cmp_size   = 0U,
        },
        .expected =
        {
            .comparison_result = 0
        }
    },
    [3] =
    {
        .name  = "TC-CMP-004: all-zeros buffers return 0",
        .input =
        {
            .fill1_byte = 0x0U,
            .fill2_byte = 0x0U,
            .buf1_size  = 64U,
            .buf2_size  = 64U,
            .cmp_size   = 64U,
        },
        .expected =
        {
            .comparison_result = 0
        }
    },
    [4] =
    {
        .name  = "TC-CMP-005: all-0xFF buffers return 0",
        .input =
        {
            .fill1_byte = 0xFFU,
            .fill2_byte = 0xFFU,
            .buf1_size  = 64U,
            .buf2_size  = 64U,
            .cmp_size   = 64U,
        },
        .expected =
        {
            .comparison_result = 0
        }
    },
    [5] =
    {
        .name  = "TC-CMP-006: first byte src1 < src2 returns negative",
        .input =
        {
            .fill1_byte = (byte_t)'a',
            .fill2_byte = (byte_t)'b',
            .buf1_size  = 64U,
            .buf2_size  = 64U,
            .cmp_size   = 1U,
        },
        .expected =
        {
            .comparison_result = (int32_t)'a' - (int32_t)'b'
        }
    },
    [6] =
    {
        .name  = "TC-CMP-007: last byte differs, src1 < src2 returns negative",
        .input =
        {
            .fill1_byte = (byte_t)'a',
            .fill2_byte = (byte_t)'b',
            .buf1_size  = 64U,
            .buf2_size  = 64U,
            .cmp_size   = 64U,
        },
        .expected =
        {
            .comparison_result = (int32_t)'a' - (int32_t)'b'
        }
    },
    [7] =
    {
        .name  = "TC-CMP-008: first byte src1 > src2 returns positive",
        .input =
        {
            .fill1_byte = (byte_t)'b',
            .fill2_byte = (byte_t)'a',
            .buf1_size  = 64U,
            .buf2_size  = 64U,
            .cmp_size   = 1U,
        },
        .expected =
        {
            .comparison_result = (int32_t)'b' - (int32_t)'a'
        }
    },
    [8] =
    {
        .name  = "TC-CMP-009: difference at first byte detected",
        .input =
        {
            .fill1_byte = 0x2,
            .fill2_byte = 0x1,
            .buf1_size  = 64U,
            .buf2_size  = 64U,
            .cmp_size   = 1U,
        },
        .expected =
        {
            .comparison_result = 1
        }
    },
    [9] =
    {
        .name  = "TC-CMP-010: difference at middle byte detected",
        .input =
        {
            .fill1_byte = 0x2,
            .fill2_byte = 0x1,
            .buf1_size  = 64U,
            .buf2_size  = 64U,
            .cmp_size   = 32U,
        },
        .expected =
        {
            .comparison_result = 1
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "memory_ops_utils_cmp",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
