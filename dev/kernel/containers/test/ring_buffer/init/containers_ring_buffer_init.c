#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "containers_ring_buffer_init_tc.h"
#include "containers_ring_buffer_usr.h"

/* Backing storage the ring buffer is initialized to point at. Its address
 * is never inspected by containers_ring_buffer_init(),
 * so a single static array is reused across every test case. */
static uint8_t                             s_backing[64];
static containers_ring_buffer_init_tc_t    s_tc;
static ring_buffer_t                       s_rb;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    /* Seed the ring buffer with the "dirty"/stale state  */
    s_rb.buffer       = NULL_PTR;
    s_rb.capacity     = 0U;
    s_rb.element_size = 0U;
    s_rb.size         = s_tc.input.dirty_size;
    s_rb.head         = s_tc.input.dirty_head;
    s_rb.tail         = s_tc.input.dirty_tail;
}

void run(void)
{
    containers_ring_buffer_init(&s_rb, (ptr_t)s_backing, s_tc.input.capacity, s_tc.input.element_size);
}

void check(void)
{
    SPEC_EXPECT_EQ_PTR(s_rb.buffer,       (ptr_t)s_backing);
    SPEC_EXPECT_EQ_U32(s_rb.capacity,     s_tc.expected.capacity);
    SPEC_EXPECT_EQ_U32(s_rb.element_size, s_tc.expected.element_size);
    SPEC_EXPECT_EQ_U32(s_rb.size,         s_tc.expected.size);
    SPEC_EXPECT_EQ_U32(s_rb.head,         s_tc.expected.head);
    SPEC_EXPECT_EQ_U32(s_rb.tail,         s_tc.expected.tail);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
