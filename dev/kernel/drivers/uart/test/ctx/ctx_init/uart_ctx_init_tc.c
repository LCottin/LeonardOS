#include "uart_ctx_init_tc.h"

const uart_ctx_init_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-UART-CTX-INIT-001: Minimum byte value",
        .input =
        {
            .io8_read_imsc_value = 0x0,
            .io32_read_cr_value  = 0x0
        },
        .expected =
        {
            .cr_addr    = 0x09000030U,
            .cr_value   = 0 | (1 << 0) | (1 << 8) | (1 << 9),
            .ismc_addr  = 0x09000038U,
            .ismc_value = 0 | (1 << 4) | (1 << 6),

            .nb_call_mmio_write32 = 1U,
            .nb_call_mmio_write8  = 1U,
            .nb_call_mmio_read32  = 1U,
            .nb_call_mmio_read8   = 1U,
        }
    },
    [1] =
    {
        .name  = "TC-UART-CTX-INIT-002: Intermediate byte value",
        .input =
        {
            .io8_read_imsc_value = 0xA5,
            .io32_read_cr_value  = 0xA5A5A5A5U
        },
        .expected =
        {
            .cr_addr    = 0x09000030U,
            .cr_value   = 0xA5A5A5A5U | (1 << 0) | (1 << 8) | (1 << 9),
            .ismc_addr  = 0x09000038U,
            .ismc_value = 0xA5 | (1 << 4) | (1 << 6),

            .nb_call_mmio_write32 = 1U,
            .nb_call_mmio_write8  = 1U,
            .nb_call_mmio_read32  = 1U,
            .nb_call_mmio_read8   = 1U,
        }
    },
    [2] =
    {
        .name  = "TC-UART-CTX-INIT-003: Maximum byte value",
        .input =
        {
            .io8_read_imsc_value = 0xFF,
            .io32_read_cr_value  = 0xFFFFFFFFU
        },
        .expected =
        {
            .cr_addr    = 0x09000030U,
            .cr_value   = 0xFFFFFFFFU | (1 << 0) | (1 << 8) | (1 << 9),
            .ismc_addr  = 0x09000038U,
            .ismc_value = 0xFF | (1 << 4) | (1 << 6),

            .nb_call_mmio_write32 = 1U,
            .nb_call_mmio_write8  = 1U,
            .nb_call_mmio_read32  = 1U,
            .nb_call_mmio_read8   = 1U,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "uart_ctx_init",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
