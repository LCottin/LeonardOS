#include "libtest.h"

void libtest_run(const test_t *test)
{
    for (uint32_t idx = 0; idx < test->test_case_count; idx++)
    {
        int test_idx_high = idx / 10 + 0x30;
        int test_idx_low  = idx % 10 + 0x30;

        libtest_print_str("[CASE");
        libtest_print_str(&test_idx_high);
        libtest_print_str(&test_idx_low);
        libtest_print_str("]: ");
        libtest_print_str(test->test_case_list[idx].test_description);
        test->test_case_list[idx].test_function();
    }
}
