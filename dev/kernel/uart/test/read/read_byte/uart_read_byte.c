#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "uart_read_byte_tc.h"
#include "uart_krn.h"

static uint32_t                 s_nb_call_mmio_read;
static uart_read_byte_tc_t      s_tc;
static char_t                   s_uart_read_return;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

byte_t mmio_io8_read(cptr_t addr)
{
    SPEC_EXPECT_EQ_PTR(addr, (ptr_t)s_tc.expected.uart_addr);

    s_nb_call_mmio_read++;

    return s_tc.input.input_byte;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_uart_read_return  = ~s_tc.input.input_byte;
    s_nb_call_mmio_read = 0U;
}

void run(void)
{
    s_uart_read_return = uart_read_byte();
}

void check(void)
{
    /* Check that mmio_read was called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_mmio_read, s_tc.expected.nb_call_mmio_read);

    /* Check that the output byte is as expected */
    SPEC_EXPECT_EQ_CHAR(s_uart_read_return, s_tc.expected.output_byte);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
