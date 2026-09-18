#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "containers_ring_buffer_pop_tc.h"
#include "containers_ring_buffer_usr.h"

/* Real backing storage for the ring buffer, large enough for every
 * capacity/element_size combination used by the test list. */
#define RB_POP_BACKING_BYTES 64U

static uint8_t                            s_backing[RB_POP_BACKING_BYTES];
static containers_ring_buffer_pop_tc_t    s_tc;
static ring_buffer_t                      s_rb;
static ptr_t                              s_result;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    spec_utils_memset(s_backing, 0, sizeof(s_backing));

    s_rb.buffer       = (ptr_t)s_backing;
    s_rb.capacity     = s_tc.input.capacity;
    s_rb.element_size = s_tc.input.element_size;
    s_rb.size         = s_tc.input.size;
    s_rb.head         = s_tc.input.head;
    s_rb.tail         = s_tc.input.tail;

    s_result = (ptr_t)s_backing;
}

void run(void)
{
    s_result = containers_ring_buffer_pop(&s_rb);
}

void check(void)
{
    if (s_tc.expected.returns_null == TRUE)
    {
        SPEC_EXPECT_EQ_PTR(s_result, NULL_PTR);
    }
    else
    {
        SPEC_EXPECT_EQ_PTR(s_result, (ptr_t)((uint8_t *)s_backing + s_tc.expected.dest_offset));
    }

    SPEC_EXPECT_EQ_U32(s_rb.head, s_tc.expected.head);
    SPEC_EXPECT_EQ_U32(s_rb.tail, s_tc.expected.tail);
    SPEC_EXPECT_EQ_U32(s_rb.size, s_tc.expected.size);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
