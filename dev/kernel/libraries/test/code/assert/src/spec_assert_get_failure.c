#include "spec_assert_krn.h"
#include "spec_assert_prv.h"

const spec_assert_failure_t *spec_assert_get_failure(size_t idx)
{
    return (idx < g_spec_assert_count) ? &g_spec_assert_failures[idx] : NULL_PTR;
}
