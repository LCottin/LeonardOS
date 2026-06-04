#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "memory_ops_usr.h"
#include "memory_ops_utils_set_tc.h"

static byte_t  s_buf1[BUFFER_SIZE];
static byte_t  s_buf1_saved[BUFFER_SIZE];
static ptr_t   s_return_addr;
static addr_t  s_buf1_addr_saved;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}

void setup(const uint32_t idx)
{
    const memory_ops_utils_set_tc_t *tc = &test_list[idx];

    spec_utils_memset(s_buf1, tc->input.fill_byte, tc->input.buf_size);

    /* Set expected buffer content */
    spec_utils_memcpy(s_buf1_saved, s_buf1, BUFFER_SIZE);
    spec_utils_memset(s_buf1_saved, (uint8_t)tc->input.data_value, tc->input.buf_size);
    s_buf1_addr_saved = (addr_t)s_buf1;
}

void run(const uint32_t idx)
{
    const memory_ops_utils_set_tc_t *tc = &test_list[idx];

    s_return_addr = memory_ops_utils_set(s_buf1 + tc->input.buf_offset, tc->input.data_value, tc->input.buf_size);
}

void check(const uint32_t idx)
{
    const memory_ops_utils_set_tc_t *tc = &test_list[idx];

    /* Check service return address */
    SPEC_EXPECT_EQ_PTR(s_return_addr, s_buf1 + tc->input.buf_offset);

    /* Check that the buffer contents were set correctly */
    SPEC_EXPECT_EQ_MEM(s_buf1 + tc->input.buf_offset, s_buf1_saved, tc->input.buf_size);

    /* Check that no bytes beyond the requested size were modified */
    if (tc->input.buf_size < BUFFER_SIZE)
    {
        SPEC_EXPECT_EQ_MEM(
            &s_buf1[tc->input.buf_size + tc->input.buf_offset],
            &s_buf1_saved[tc->input.buf_size + tc->input.buf_offset],
            BUFFER_SIZE - tc->input.buf_size - tc->input.buf_offset);
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
