#include "spec_assert_krn.h"
#include "spec_assert_prv.h"

void spec_assert_record_equal_u64(const uint64_t got, const uint64_t exp, const char_t *file, const int32_t line)
{
    spec_assert_record_equal(got, exp, sizeof(uint64_t), file, line);
}
