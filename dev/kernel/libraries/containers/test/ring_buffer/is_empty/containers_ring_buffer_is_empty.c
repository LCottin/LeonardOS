#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "containers_ring_buffer_is_empty_tc.h"
#include "containers_ring_buffer_usr.h"

static containers_ring_buffer_is_empty_tc_t    s_tc;
static ring_buffer_t                           s_rb;
static bool_t                                  s_result;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_rb.buffer       = NULL_PTR;
    s_rb.capacity     = s_tc.input.capacity;
    s_rb.element_size = s_tc.input.element_size;
    s_rb.size         = s_tc.input.size;
    s_rb.head         = s_tc.input.head;
    s_rb.tail         = s_tc.input.tail;

    s_result = (bool_t)!s_tc.expected.is_empty;
}

void run(void)
{
    s_result = containers_ring_buffer_is_empty(&s_rb);
}

void check(void)
{
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
