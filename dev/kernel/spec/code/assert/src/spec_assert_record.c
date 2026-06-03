#include "spec_assert_prv.h"
#include "spec_assert_krn.h"

void spec_assert_record(const bool_t cond, const char_t *file, const int32_t line, const char_t *desc)
{
    if ((cond == FALSE) && (g_spec_assert_count < SPEC_MAX_FAILURES))
    {
        g_spec_assert_failures[g_spec_assert_count].file       = file;
        g_spec_assert_failures[g_spec_assert_count].line       = line;
        g_spec_assert_failures[g_spec_assert_count].desc       = desc;
        g_spec_assert_failures[g_spec_assert_count].has_values = FALSE;
        g_spec_assert_count++;
    }
}
