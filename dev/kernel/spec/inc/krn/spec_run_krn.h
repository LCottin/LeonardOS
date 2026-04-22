#ifndef __SPEC_RUN_KRN_H__
#define __SPEC_RUN_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Single unit-test case.
 **********************************************************************/
typedef struct
{
    const char *name;            /* Human-readable label emitted in TAP output */
    void      (*setup)(void);    /* Called before run(). Resets static stub pools. May be NULL. */
    void      (*run)(void);      /* Exercises the unit under test (no assertions here). */
    bool_t    (*check)(void);    /* Inspects state, returns true if passed, false otherwise. */
} spec_run_case_t;


/**********************************************************************
 * @brief Run every case in a suite and emit TAP 13 to stdout.
 *
 * @param suite_name Label printed as a TAP comment.
 * @param cases Array of cases descriptors.
 * @param count Number of elements in cases[].
 * @return None.
 **********************************************************************/
extern void spec_run_suite(const char            *suite_name,
                           const spec_run_case_t *cases,
                           const size_t           count);


/**********************************************************************
 * @brief Entry point for test suites. Called by the test runner.
 *
 * @param None.
 * @return None.
 * @note This function does not return.
 **********************************************************************/
extern void test_suite_entry(void);


#endif /* __SPEC_RUN_KRN_H__ */
