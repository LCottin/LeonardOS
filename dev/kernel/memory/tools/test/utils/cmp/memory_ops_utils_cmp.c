#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "memory_ops_usr.h"
#include "memory_ops_utils_cmp_tc.h"

static byte_t                    s_buf1[BUFFER_SIZE];
static byte_t                    s_buf2[BUFFER_SIZE];
static byte_t                    s_buf1_saved[BUFFER_SIZE];
static byte_t                    s_buf2_saved[BUFFER_SIZE];
static int32_t                   s_return_value;
static memory_ops_utils_cmp_tc_t s_tc;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    /* Initialize buffers with initial values */
    spec_utils_memset(s_buf1, s_tc.input.init1_byte, BUFFER_SIZE);
    spec_utils_memset(s_buf2, s_tc.input.init2_byte, BUFFER_SIZE);

    /* Fill buffers with specified values */
    spec_utils_memset(s_buf1, s_tc.input.fill1_byte, s_tc.input.buf1_size);
    spec_utils_memset(s_buf2, s_tc.input.fill2_byte, s_tc.input.buf2_size);

    /* Save original buffer contents for later comparison */
    spec_utils_memcpy(s_buf1_saved, s_buf1, s_tc.input.buf1_size);
    spec_utils_memcpy(s_buf2_saved, s_buf2, s_tc.input.buf2_size);
}

void run(void)
{
    s_return_value = memory_ops_utils_cmp(s_buf1, s_buf2, s_tc.input.cmp_size);
}

void check(void)
{
    /* Check service return code */
    SPEC_EXPECT_EQ_U32(s_return_value, s_tc.expected.comparison_result);

    /* Check that buffers were not modified */
    SPEC_EXPECT_EQ_MEM(s_buf1, s_buf1_saved, s_tc.input.cmp_size);
    SPEC_EXPECT_EQ_MEM(s_buf2, s_buf2_saved, s_tc.input.cmp_size);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
