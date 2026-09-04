#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "console_buffer_is_empty_tc.h"
#include "console_krn.h"
#include "console_ctx.h"

static uint32_t                       s_nb_call_rb_is_empty;
static console_buffer_is_empty_tc_t   s_tc;
static bool_t                         s_result;

ring_buffer_t console_ring_buffer;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

bool_t containers_ring_buffer_is_empty(const ring_buffer_t *rb)
{
    SPEC_EXPECT_EQ_PTR(rb, (ptr_t)&console_ring_buffer);

    s_nb_call_rb_is_empty++;

    return s_tc.input.rb_is_empty;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_rb_is_empty = 0U;
    s_result              = (bool_t)!s_tc.expected.is_empty;
}

void run(void)
{
    s_result = console_buffer_is_empty();
}

void check(void)
{
    /* Check that containers_ring_buffer_is_empty was called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_rb_is_empty, s_tc.expected.nb_call_rb_is_empty);

    /* Check that the returned value is as expected */
    SPEC_EXPECT_EQ_U8(s_result, s_tc.expected.is_empty);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
