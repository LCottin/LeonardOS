#ifndef __SPEC_RUN_KRN_H__
#define __SPEC_RUN_KRN_H__

#include "types_usr.h"
#include "spec_assert_krn.h"

/**********************************************************************
 * @brief Test suite structure.
 **********************************************************************/
typedef struct
{
    const char_t   *suite_name;                         /* Human-readable label emitted in TAP output */
    const char_t   *(*tc_name)(const uint32_t idx);     /* NULL → index label */
    void            (*setup)(const uint32_t idx);       /* Called before run(). Resets static stub pools. May be NULL. */
    void            (*run)(void);                       /* Exercises the unit under test (no assertions here). */
    void            (*check)(void);                     /* Inspects state */
    size_t          tc_count;                           /* Number of test cases in the suite */
    uint8_t         reserved[4];                        /* Reserved for future use */
} spec_run_suite_t;


/**********************************************************************
 * @brief Run every case in a suite and emit TAP 13 to stdout.
 *
 * @param suite  The test suite to run.
 * @return None.
 **********************************************************************/
extern void spec_run_suite(const spec_run_suite_t *suite);


/**********************************************************************
 * @brief Entry point for test suites. Called by the test runner.
 *
 * @param None.
 * @return None.
 * @note This function does not return.
 **********************************************************************/
extern void test_suite_entry(void);


#endif /* __SPEC_RUN_KRN_H__ */
