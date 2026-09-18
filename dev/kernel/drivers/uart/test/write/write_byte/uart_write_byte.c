#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "uart_write_byte_tc.h"
#include "uart_krn.h"

static uint32_t                  s_nb_call_mmio_write;
static uart_write_byte_tc_t      s_tc;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void mmio_io8_write(ptr_t addr, const uint8_t value)
{
    SPEC_EXPECT_EQ_U8(value, s_tc.expected.output_byte);
    SPEC_EXPECT_EQ_PTR(addr, (ptr_t)s_tc.expected.uart_addr);

    s_nb_call_mmio_write++;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_mmio_write = 0U;
}

void run(void)
{
    uart_write_byte(s_tc.input.input_byte);
}

void check(void)
{
    /* Check that mmio_write was called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_mmio_write, s_tc.expected.nb_call_mmio_write);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
