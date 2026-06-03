#include "spec_assert_prv.h"
#include "spec_assert_krn.h"

uint32_t spec_assert_get_count(void)
{
    return g_spec_assert_count;
}
