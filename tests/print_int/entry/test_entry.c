#include "libtest.h"
#include "test_entry.h"
#include "print_int.h"

test_t g_test;

void _test_entry()
{
    /* Test definition goes here */
    const char_t test_name[64]         = "print_integers";
    const test_case_t test_case_list[] =
    {
        [0] =
        {
            .test_description     = "Print signed value in decimal base",
            .test_function        = &print_int_positive,
            .test_input.input_i64 = 123,
            .expected_result      = "123",
        }
    };

    /* Test preparation goes here */
    libtest_memcpy(g_test.test_name,      test_name,      sizeof(test_name));
    libtest_memcpy(g_test.test_case_list, test_case_list, sizeof(test_case_list));
    g_test.test_case_count = sizeof(test_case_list) / sizeof(test_case_list[0]);

    /* Launch test framework */
    libtest_start(&g_test);
    libtest_run(&g_test);
    libtest_finish(&g_test);
}
