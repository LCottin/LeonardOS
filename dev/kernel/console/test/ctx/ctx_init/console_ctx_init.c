#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "console_ctx_init_tc.h"
#include "console_krn.h"
#include "console_ctx.h"
#include "console_ctx_prv.h"
#include "console_irq.h"
#include "containers_ring_buffer_usr.h"
#include "irq_krn.h"

static uint32_t                 s_nb_call_rb_init;
static uint32_t                 s_nb_call_irq_register;
static console_ctx_init_tc_t    s_tc;

ring_buffer_t console_ring_buffer;
char_t        console_buffer[CONSOLE_BUFFER_SIZE];

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void console_irq_rx(void)
{
}

void containers_ring_buffer_init(ring_buffer_t *rb, ptr_t buffer, const size_t capacity, const size_t element_size)
{
    SPEC_EXPECT_EQ_PTR(rb, (ptr_t)&console_ring_buffer);
    SPEC_EXPECT_EQ_PTR(buffer, (ptr_t)console_buffer);
    SPEC_EXPECT_EQ_U32(capacity, s_tc.expected.expected_capacity);
    SPEC_EXPECT_EQ_U32(element_size, s_tc.expected.expected_element_size);

    s_nb_call_rb_init++;
}

void irq_core_register(const uint32_t irq_nb, irq_handler_t handler)
{
    SPEC_EXPECT_EQ_U32(irq_nb, s_tc.expected.expected_irq_nb);
    SPEC_EXPECT_EQ_PTR((ptr_t)handler, (ptr_t)&console_irq_rx);

    s_nb_call_irq_register++;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_rb_init        = 0U;
    s_nb_call_irq_register   = 0U;
}

void run(void)
{
    for (uint32_t i = 0U; i < s_tc.input.call_count; i++)
    {
        console_ctx_init();
    }
}

void check(void)
{
    /* Check that the dependencies were called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_rb_init,        s_tc.expected.nb_call_rb_init);
    SPEC_EXPECT_EQ_U32(s_nb_call_irq_register,   s_tc.expected.nb_call_irq_register);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
