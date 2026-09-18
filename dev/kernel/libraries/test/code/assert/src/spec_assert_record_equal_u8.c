#include "spec_assert_krn.h"
#include "spec_assert_prv.h"

void spec_assert_record_equal_u8(const uint8_t got, const uint8_t exp, const char_t *file, const int32_t line)
{
    spec_assert_record_equal((uint64_t)got, (uint64_t)exp, sizeof(uint8_t), file, line);
}
