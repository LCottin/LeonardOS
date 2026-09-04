#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "console_buffer_pop_tc.h"
#include "console_krn.h"
#include "console_ctx.h"
#include "containers_ring_buffer_usr.h"

static uint32_t                  s_nb_call_rb_pop;
static console_buffer_pop_tc_t   s_tc;
static char_t                    s_popped_storage;
static char_t                    s_result;

ring_buffer_t console_ring_buffer;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

ptr_t containers_ring_buffer_pop(ring_buffer_t *rb)
{
    ptr_t ret;

    SPEC_EXPECT_EQ_PTR(rb, (ptr_t)&console_ring_buffer);

    if (s_tc.input.rb_is_empty == TRUE)
    {
        ret = NULL_PTR;
    }
    else
    {
        s_popped_storage = s_tc.input.popped_byte;
        ret = (ptr_t)&s_popped_storage;
    }

    s_nb_call_rb_pop++;

    return ret;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_rb_pop = 0U;
    s_result         = ~s_tc.expected.output_byte;
}

void run(void)
{
    s_result = console_buffer_pop();
}

void check(void)
{
    /* Check that containers_ring_buffer_pop was called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_rb_pop, s_tc.expected.nb_call_rb_pop);

    /* Check that the returned byte is as expected */
    SPEC_EXPECT_EQ_CHAR(s_result, s_tc.expected.output_byte);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
