#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "memory_ops_usr.h"
#include "memory_ops_utils_copy_tc.h"

static byte_t                     s_buf1[BUFFER_SIZE];
static byte_t                     s_buf1_saved[BUFFER_SIZE];
static byte_t                     s_buf2[BUFFER_SIZE];
static byte_t                     s_buf2_saved[BUFFER_SIZE];
static ptr_t                      s_return_addr;
static addr_t                     s_buf2_addr_saved;
static memory_ops_utils_copy_tc_t s_tc;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    spec_utils_memset(s_buf1, s_tc.input.fill1_byte, s_tc.input.buf1_size);
    spec_utils_memset(s_buf2, s_tc.input.fill2_byte, s_tc.input.buf2_size);

    /* Save original buffer contents for later comparison */
    spec_utils_memcpy(s_buf1_saved, s_buf1, BUFFER_SIZE);
    spec_utils_memcpy(s_buf2_saved, s_buf2, BUFFER_SIZE);
    s_buf2_addr_saved = (addr_t)s_buf2;
}

void run(void)
{
    s_return_addr = memory_ops_utils_copy(s_buf2 + s_tc.input.dest_offset, s_buf1 + s_tc.input.src_offset, s_tc.input.copy_size);
}

void check(void)
{
    /* Check service return address */
    SPEC_EXPECT_EQ_PTR(s_return_addr, s_buf2 + s_tc.input.dest_offset);

    /* Check that the buffer contents were copied correctly */
    SPEC_EXPECT_EQ_MEM(s_buf2 + s_tc.input.dest_offset, s_buf1 + s_tc.input.src_offset, s_tc.input.copy_size);

    /* Check that no byte were written beyond requested size */
    if (s_tc.input.copy_size < BUFFER_SIZE)
    {
        SPEC_EXPECT_EQ_MEM(
            &s_buf2[s_tc.input.copy_size + s_tc.input.dest_offset],
            &s_buf2_saved[s_tc.input.copy_size + s_tc.input.dest_offset],
            BUFFER_SIZE - s_tc.input.copy_size - s_tc.input.dest_offset);
    }

    /* Check that s_buf2 address was not modified */
    SPEC_EXPECT_EQ_PTR(s_buf2, s_buf2_addr_saved);

    /* Check that s_buf1 was not modified */
    SPEC_EXPECT_EQ_MEM(s_buf1, s_buf1_saved, s_tc.input.buf1_size);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
