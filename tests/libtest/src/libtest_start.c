#include "libtest.h"

void libtest_start(const test_t *test)
{
    libtest_print_str("[TEST]: Launching ");
    libtest_print_str(test->test_name);
    libtest_print_str("\n");
}
