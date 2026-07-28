#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "uart_ctx_init_tc.h"
#include "uart_krn.h"

static uint32_t                s_nb_call_mmio_write8;
static uint32_t                s_nb_call_mmio_write32;
static uint32_t                s_nb_call_mmio_read8;
static uint32_t                s_nb_call_mmio_read32;
static uart_ctx_init_tc_t      s_tc;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void mmio_io8_write(ptr_t addr, const uint8_t value)
{
    SPEC_EXPECT_EQ_U8(value, s_tc.expected.ismc_value);
    SPEC_EXPECT_EQ_PTR(addr, (ptr_t)s_tc.expected.ismc_addr);

    s_nb_call_mmio_write8++;
}

void mmio_io32_write(ptr_t addr, const uint32_t value)
{
    SPEC_EXPECT_EQ_U8(value, s_tc.expected.cr_value);
    SPEC_EXPECT_EQ_PTR(addr, (ptr_t)s_tc.expected.cr_addr);

    s_nb_call_mmio_write32++;
}

uint8_t mmio_io8_read(cptr_t addr)
{
    SPEC_EXPECT_EQ_PTR(addr, (ptr_t)s_tc.expected.ismc_addr);

    s_nb_call_mmio_read8++;

    return s_tc.input.io8_read_imsc_value;
}

uint32_t mmio_io32_read(cptr_t addr)
{
    SPEC_EXPECT_EQ_PTR(addr, (ptr_t)s_tc.expected.cr_addr);

    s_nb_call_mmio_read32++;

    return s_tc.input.io32_read_cr_value;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_mmio_write8  = 0;
    s_nb_call_mmio_write32 = 0;
    s_nb_call_mmio_read8   = 0;
    s_nb_call_mmio_read32  = 0;
}

void run(void)
{
    uart_ctx_init();
}

void check(void)
{
    /* Check that mmio_write was called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_mmio_write8,  s_tc.expected.nb_call_mmio_write8);
    SPEC_EXPECT_EQ_U32(s_nb_call_mmio_write32, s_tc.expected.nb_call_mmio_write32);
    SPEC_EXPECT_EQ_U32(s_nb_call_mmio_read8,   s_tc.expected.nb_call_mmio_read8);
    SPEC_EXPECT_EQ_U32(s_nb_call_mmio_read32,  s_tc.expected.nb_call_mmio_read32);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
