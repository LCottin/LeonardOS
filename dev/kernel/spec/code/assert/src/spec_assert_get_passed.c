#include "spec_assert_prv.h"
#include "spec_assert_krn.h"

bool_t spec_assert_get_passed(void)
{
    return g_spec_assert_count == 0U ? TRUE : FALSE;
}
