#include "spec_assert_prv.h"
#include "spec_assert.h"

void spec_assert_reset(void)
{
    g_spec_assert_count = 0U;
}
