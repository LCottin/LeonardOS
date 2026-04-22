#include "spec_run_krn.h"
#include "spec_utils_krn.h"

void spec_run_suite(const char            *suite_name,
                    const spec_run_case_t *cases,
                    const size_t           count)
{
    spec_utils_print_string("\nTAP version 13\n1..");
    spec_utils_print_uint(count);
    spec_utils_print_string("\n# Running suite: ");
    spec_utils_print_string(suite_name);
    spec_utils_print_string("\n");

    uint32_t failed = 0;

    for (size_t idx = 0U; idx < count; idx++)
    {
        const spec_run_case_t *tc = &cases[idx];

        spec_utils_print_string("\t");
        spec_utils_print_uint(idx + 1U);
        spec_utils_print_string(" - ");
        spec_utils_print_string(tc->name);
        spec_utils_print_string(": ");

        /* Reset stub pools */
        if (tc->setup != NULL)
        {
            tc->setup();
        }

        /* Exercise the unit */
        tc->run();

        /* Inspect results */
        const bool_t result = tc->check();

        if (result == TRUE)
        {
            spec_utils_print_string("OK\n");
        }
        else
        {
            spec_utils_print_string("NOK\n");
            failed++;
        }
    }

    /* Summary comment */
    spec_utils_print_string("# End of suite\n");
    spec_utils_print_uint(count - failed);
    spec_utils_print_string("/");
    spec_utils_print_uint(count);
    spec_utils_print_string(" passed\n");
}
