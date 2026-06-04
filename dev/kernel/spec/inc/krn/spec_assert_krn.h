#ifndef __SPEC_ASSERT_KRN_H__
#define __SPEC_ASSERT_KRN_H__

#include "types_usr.h"


/**********************************************************************
 * Constants
 **********************************************************************/
#define SPEC_MAX_FAILURES 16U


/**********************************************************************
 * @brief Single recorded assertion failure.
 *
 * When desc is non-NULL the failure came from SPEC_EXPECT and the
 * string is printed directly.
 * When desc is NULL the failure came from a typed SPEC_EXPECT_EQ_*
 * macro and got/exp are printed as hex values.
 **********************************************************************/
typedef struct
{
    const char_t *file;         /* source file where the assertion occurred */
    const char_t *desc;         /* non-NULL → free text assertion        */
    int32_t       line;         /* source line where the assertion occurred */
    bool_t        has_values;   /* TRUE     → print got / exp            */
    uint64_t      got;          /* value obtained from the code under test (valid if has_values) */
    uint64_t      exp;          /* expected value (valid if has_values) */
    size_t        size;         /* number of bytes to compare for array assertions, 0 for scalar assertions */
    byte_t        reserved[4];  /* Reserved for future use, set to 0 */
} spec_assert_failure_t;


/**********************************************************************
 * @brief Record a boolean assertion failure.
 *
 * @param cond   The condition being asserted.  FALSE indicates failure.
 * @param file   The source file where the assertion occurred.
 * @param line   The source line where the assertion occurred.
 * @param desc   A free-text description of the assertion.
 * @return None.
 **********************************************************************/
extern void spec_assert_record(const bool_t cond, const char_t *file, const int32_t line, const char_t *desc);


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
extern void spec_assert_record_equal_u8 (const uint8_t  got, const uint8_t  exp,                    const char_t *file, const int32_t line);
extern void spec_assert_record_equal_u32(const uint32_t got, const uint32_t exp,                    const char_t *file, const int32_t line);
extern void spec_assert_record_equal_ptr(cptr_t         got, cptr_t         exp,                    const char_t *file, const int32_t line);
extern void spec_assert_record_equal_mem(cptr_t         got, cptr_t         exp, const size_t size, const char_t *file, const int32_t line);


/**********************************************************************
 * @brief Return whether all assertions have passed so far.
 *
 * @param None.
 * @return TRUE if no assertions have failed, FALSE otherwise.
 **********************************************************************/
extern bool_t spec_assert_get_passed(void);


/**************************************************************
 * @brief Return the number of recorded assertion failures.
 *
 * @param None.
 * @return The number of recorded assertion failures.
 **********************************************************************/
extern uint32_t spec_assert_get_count(void);


/**********************************************************************
 * @brief Return the idx'th recorded assertion failure.
 *
 * @param idx  The index of the failure to return, in the range [0, count-1].
 * @return The idx'th recorded assertion failure, or NULL_PTR if idx is out of range.
 **********************************************************************/
extern const spec_assert_failure_t *spec_assert_get_failure(const size_t idx);


/**********************************************************************
 * Macros — usable from run(), check(), or any stub.
 *
 * SPEC_EXPECT        — boolean condition + free-text description.
 * SPEC_EXPECT_EQ_U8  — uint8_t equality, prints got/exp on failure.
 * SPEC_EXPECT_EQ_U32 — uint32_t equality, prints got/exp on failure.
 * SPEC_EXPECT_EQ_PTR — pointer equality, prints got/exp on failure.
 * SPEC_EXPECT_EQ_MEM — memory equality, prints got/exp on failure.
 *
 * __FILE__ and __LINE__ are captured automatically; callers add nothing.
 **********************************************************************/
#define SPEC_EXPECT(cond, desc) \
    spec_assert_record((bool_t)(cond), __FILE__, __LINE__, (desc))

#define SPEC_EXPECT_EQ_U8(got, exp) \
    spec_assert_record_equal_u8((uint8_t)(got), (uint8_t)(exp), __FILE__, __LINE__)

#define SPEC_EXPECT_EQ_U32(got, exp) \
    spec_assert_record_equal_u32((uint32_t)(got), (uint32_t)(exp), __FILE__, __LINE__)

#define SPEC_EXPECT_EQ_PTR(got, exp) \
    spec_assert_record_equal_ptr((ptr_t)(got), (ptr_t)(exp), __FILE__, __LINE__)

#define SPEC_EXPECT_EQ_MEM(got, exp, size) \
    spec_assert_record_equal_mem((ptr_t)(got), (ptr_t)(exp), (size), __FILE__, __LINE__)

#define SPEC_ASSERT_UNUSED(expr) \
    (void)(expr) /* silence unused parameter warning */

#endif /*_ SPEC_ASSERT_KRN_H__ */
