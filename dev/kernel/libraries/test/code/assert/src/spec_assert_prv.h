#ifndef __SPEC_ASSERT_PRV_H__
#define __SPEC_ASSERT_PRV_H__

#include "types_usr.h"
#include "spec_assert_krn.h"

/**********************************************************************
 * @brief Typed equality checkers.
 *
 * @param got    The value obtained from the code under test.
 * @param exp    The expected value.
 * @param size   The number of bytes to compare.
 * @param file   The source file where the assertion occurred.
 * @param line   The source line where the assertion occurred.
 * @return None.
 **********************************************************************/
extern void spec_assert_record_equal(const uint64_t got, const uint64_t exp, const size_t size, const char_t *file, const int32_t line);


/**********************************************************************
 * @brief Global counter of recorded assertion failures.
 **********************************************************************/
extern uint32_t g_spec_assert_count;


/**********************************************************************
 * @brief Global array of recorded assertion failures.
 **********************************************************************/
extern spec_assert_failure_t g_spec_assert_failures[SPEC_MAX_FAILURES];


#endif /* __SPEC_ASSERT_PRV_H__ */
