#include "spec_assert_prv.h"
#include "spec_assert_krn.h"

void spec_assert_record_equal(const uint64_t got, const uint64_t exp, const size_t size, const char_t *file, const int32_t line)
{
    if ((got != exp) && (g_spec_assert_count < SPEC_MAX_FAILURES))
    {
        g_spec_assert_failures[g_spec_assert_count].file       = file;
        g_spec_assert_failures[g_spec_assert_count].line       = line;
        g_spec_assert_failures[g_spec_assert_count].desc       = NULL_PTR;
        g_spec_assert_failures[g_spec_assert_count].has_values = TRUE;
        g_spec_assert_failures[g_spec_assert_count].got        = got;
        g_spec_assert_failures[g_spec_assert_count].exp        = exp;
        g_spec_assert_failures[g_spec_assert_count].size       = size;
        g_spec_assert_count++;
    }
}
