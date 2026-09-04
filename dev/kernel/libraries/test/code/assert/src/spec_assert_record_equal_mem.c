#include "spec_assert_prv.h"
#include "spec_assert_krn.h"
#include "spec_utils_krn.h"

void spec_assert_record_equal_mem(cptr_t got, cptr_t exp, const size_t size, const char_t *file, const int32_t line)
{
    /* compare memory area content pointed by got and exp*/
    if ((spec_utils_memcmp(got, exp, size) != 0) && (g_spec_assert_count < SPEC_MAX_FAILURES))
    {
        g_spec_assert_failures[g_spec_assert_count].file       = file;
        g_spec_assert_failures[g_spec_assert_count].line       = line;
        g_spec_assert_failures[g_spec_assert_count].desc       = NULL_PTR;
        g_spec_assert_failures[g_spec_assert_count].has_values = TRUE;
        g_spec_assert_failures[g_spec_assert_count].got        = (uint64_t)got;
        g_spec_assert_failures[g_spec_assert_count].exp        = (uint64_t)exp;
        g_spec_assert_failures[g_spec_assert_count].size       = size;
        g_spec_assert_count++;
    }
}
