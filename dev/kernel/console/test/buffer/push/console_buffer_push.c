#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "console_buffer_push_tc.h"
#include "console_krn.h"
#include "console_ctx.h"
#include "containers_ring_buffer_usr.h"

static uint32_t                   s_nb_call_rb_push;
static console_buffer_push_tc_t   s_tc;

ring_buffer_t console_ring_buffer;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void containers_ring_buffer_push(ring_buffer_t *rb, cptr_t element)
{
    SPEC_EXPECT_EQ_PTR(rb, (ptr_t)&console_ring_buffer);
    SPEC_EXPECT_EQ_CHAR(*(const char_t *)element, s_tc.expected.output_byte);

    s_nb_call_rb_push++;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_rb_push = 0U;
}

void run(void)
{
    console_buffer_push(s_tc.input.input_byte);
}

void check(void)
{
    /* Check that containers_ring_buffer_push was called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_rb_push, s_tc.expected.nb_call_rb_push);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
