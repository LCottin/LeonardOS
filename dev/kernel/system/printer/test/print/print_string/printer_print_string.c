#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "printer_krn.h"
#include "printer_print_string_tc.h"

static printer_print_string_tc_t s_tc;
static uint32_t                  s_nb_uart_call;
static addr_t                    s_input_addr;

void uart_write_byte(const uint8_t byte)
{
    SPEC_EXPECT_EQ_U8(byte, s_tc.input.str[s_nb_uart_call]);
    s_nb_uart_call++;
}

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    /* Reset call to function call */
    s_nb_uart_call = 0;

    /* Set expected buffer content */
    s_input_addr = (addr_t)s_tc.input.str;
}

void run(void)
{
    printer_print_string((cptr_t)s_tc.input.str);
}

void check(void)
{
    /* Check number of UART calls */
    SPEC_EXPECT_EQ_U32(s_nb_uart_call, s_tc.output.nb_call_uart);

    /* Check that s_input_addr address was not modified */
    SPEC_EXPECT_EQ_PTR((ptr_t)s_input_addr, (ptr_t)s_tc.input.str);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
