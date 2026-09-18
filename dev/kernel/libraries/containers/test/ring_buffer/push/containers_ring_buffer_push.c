#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "containers_ring_buffer_push_tc.h"
#include "containers_ring_buffer_usr.h"

/* Real backing storage for the ring buffer, large enough for every
 * capacity/element_size combination used by the test list. */
#define RB_PUSH_BACKING_BYTES 64U

static uint8_t                              s_backing[RB_PUSH_BACKING_BYTES];
static uint32_t                             s_nb_call_copy;
static ptr_t                                s_last_dest;
static size_t                               s_last_size;
static containers_ring_buffer_push_tc_t     s_tc;
static ring_buffer_t                        s_rb;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void memory_ops_utils_copy(ptr_t dest, cptr_t src, const size_t size)
{
    SPEC_EXPECT_EQ_PTR(dest, (ptr_t)((uint8_t *)s_backing + s_tc.expected.dest_offset));
    SPEC_EXPECT_EQ_U32(size, s_tc.expected.copy_size);

    spec_utils_memcpy(dest, src, size);

    s_last_dest = dest;
    s_last_size = size;
    s_nb_call_copy++;
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

    s_nb_call_copy = 0U;
    s_last_dest    = NULL_PTR;
    s_last_size    = 0U;
}

void run(void)
{
    containers_ring_buffer_push(&s_rb, (cptr_t)s_tc.input.elements);
}

void check(void)
{
    /* Check that memory_ops_utils_copy was called the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_copy, s_tc.expected.nb_call_copy);

    /* Check that the ring buffer bookkeeping fields were updated correctly */
    SPEC_EXPECT_EQ_U32(s_rb.head, s_tc.expected.head);
    SPEC_EXPECT_EQ_U32(s_rb.tail, s_tc.expected.tail);
    SPEC_EXPECT_EQ_U32(s_rb.size, s_tc.expected.size);

    /* Check that the element bytes actually landed at the expected offset */
    for (uint32_t i = 0U; i < s_tc.input.element_size; i++)
    {
        SPEC_EXPECT_EQ_U8(s_backing[s_tc.expected.dest_offset + i], s_tc.input.elements[i]);
    }
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
