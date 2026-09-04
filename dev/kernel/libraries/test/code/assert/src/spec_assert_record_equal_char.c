#include "spec_assert_krn.h"
#include "spec_assert_prv.h"

void spec_assert_record_equal_char(const char_t got, const char_t exp, const char_t *file, const int32_t line)
{
    spec_assert_record_equal((uint64_t)got, (uint64_t)exp, sizeof(char_t), file, line);
}
