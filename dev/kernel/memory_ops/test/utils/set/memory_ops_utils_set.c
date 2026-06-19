#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "memory_ops_usr.h"
#include "memory_ops_utils_set_tc.h"

static byte_t                    s_buf1[BUFFER_SIZE];
static byte_t                    s_buf1_saved[BUFFER_SIZE];
static ptr_t                     s_return_addr;
static addr_t                    s_buf1_addr_saved;
static memory_ops_utils_set_tc_t s_tc;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    spec_utils_memset(s_buf1, s_tc.input.fill_byte, s_tc.input.buf_size);

    /* Set expected buffer content */
    spec_utils_memcpy(s_buf1_saved, s_buf1, BUFFER_SIZE);
    spec_utils_memset(s_buf1_saved, (uint8_t)s_tc.input.data_value, s_tc.input.buf_size);
    s_buf1_addr_saved = (addr_t)s_buf1;
}

void run(void)
{
    s_return_addr = memory_ops_utils_set(s_buf1 + s_tc.input.buf_offset, s_tc.input.data_value, s_tc.input.buf_size);
}

void check(void)
{
    /* Check service return address */
    SPEC_EXPECT_EQ_PTR(s_return_addr, s_buf1 + s_tc.input.buf_offset);

    /* Check that the buffer contents were set correctly */
    SPEC_EXPECT_EQ_MEM(s_buf1 + s_tc.input.buf_offset, s_buf1_saved, s_tc.input.buf_size);

    /* Check that no bytes beyond the requested size were modified */
    if (s_tc.input.buf_size < BUFFER_SIZE)
    {
        SPEC_EXPECT_EQ_MEM(
            &s_buf1[s_tc.input.buf_size + s_tc.input.buf_offset],
            &s_buf1_saved[s_tc.input.buf_size + s_tc.input.buf_offset],
            BUFFER_SIZE - s_tc.input.buf_size - s_tc.input.buf_offset);
    }

    /* Check that s_buf1 address was not modified */
    SPEC_EXPECT_EQ_PTR(s_buf1, s_buf1_addr_saved);
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
