#include "libtest.h"

void libtest_finish(const test_t *test)
{
    (void)test;
    libtest_print_str("[TEST]: Done\n");
}
