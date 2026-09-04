#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "spec_assert.h"

void spec_run_suite(const spec_run_suite_t *suite)
{
    spec_utils_print_string("\r\nTAP version 13\r\n1..");
    spec_utils_print_uint(suite->tc_count);
    spec_utils_print_string("\r\n# Running suite: ");
    spec_utils_print_string(suite->suite_name);
    spec_utils_print_string("\r\n");

    uint32_t failed = 0;

    for (size_t idx = 0U; idx < suite->tc_count; idx++)
    {
        /* Reset context */
        spec_assert_reset();

        spec_utils_print_string("\t");
        spec_utils_print_uint(idx + 1U);
        spec_utils_print_string(" - ");
        spec_utils_print_string(suite->tc_name != NULL ? suite->tc_name(idx) : "Test case");
        spec_utils_print_string(": ");


        /* Setup test case */
        if (suite->setup != NULL_PTR)
        {
            suite->setup(idx);
        }

        /* Exercise the unit */
        SPEC_EXPECT(suite->run != NULL_PTR, "Suite run() function is required");
        if (suite->run != NULL_PTR)
        {
            suite->run();
        }

        /* Inspect results */
        if (suite->check != NULL_PTR)
        {
            suite->check();
        }

        /* ── TAP result line ──────────────────────────────────── */

        if (spec_assert_get_passed() == TRUE)
        {
            spec_utils_print_string("OK\r\n");
        }
        else
        {
            spec_utils_print_string("NOK\r\n");
            failed++;
        }

        /* ── TAP diagnostics: one line per failed assertion ───── */

        const uint32_t assert_count = spec_assert_get_count();
        for (size_t fail_idx = 0U; fail_idx < assert_count; fail_idx++)
        {
            const spec_assert_failure_t *fail = spec_assert_get_failure(fail_idx);

            spec_utils_print_string("\t\t# FAILED: ");
            spec_utils_print_string(" (");
            spec_utils_print_string(fail->file);
            spec_utils_print_string(":");
            spec_utils_print_uint((uint32_t)fail->line);
            spec_utils_print_string(") ");

            if (fail->has_values == TRUE)
            {
                spec_utils_print_string("got = ");
                spec_utils_print_uint(fail->got);
                spec_utils_print_string(", expected = ");
                spec_utils_print_uint(fail->exp);
                spec_utils_print_string(", size = ");
                spec_utils_print_uint(fail->size);
            }
            else
            {
                spec_utils_print_string(fail->desc);
            }

            spec_utils_print_string("\r\n");
        }
    }

    /* Summary comment */
    spec_utils_print_string("# End of suite\r\n# ");
    spec_utils_print_uint(suite->tc_count - failed);
    spec_utils_print_string("/");
    spec_utils_print_uint(suite->tc_count);
    spec_utils_print_string(" passed\r\n");
}
