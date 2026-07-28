#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "console_irq_rx_tc.h"
#include "console_krn.h"
#include "console_irq.h"

static uint32_t             s_nb_call_uart_read;
static uint32_t             s_nb_call_buffer_push;
static console_irq_rx_tc_t  s_tc;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

char_t uart_read_byte(void)
{
    s_nb_call_uart_read++;

    return s_tc.input.input_byte;
}

void console_buffer_push(const char_t c)
{
    SPEC_EXPECT_EQ_CHAR(c, s_tc.expected.pushed_byte);

    s_nb_call_buffer_push++;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_uart_read   = 0U;
    s_nb_call_buffer_push = 0U;
}

void run(void)
{
    console_irq_rx();
}

void check(void)
{
    /* Check that the dependencies were called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_uart_read,   s_tc.expected.nb_call_uart_read);
    SPEC_EXPECT_EQ_U32(s_nb_call_buffer_push, s_tc.expected.nb_call_buffer_push);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
