#ifndef __LIB_TEST_H__
#define __LIB_TEST_H__

#include "types_usr.h"

typedef union
{
    void     *input_ptr;
    int64_t   input_i64;
    float64_t input_flt;
    uint64_t  input_u64;
} test_input_t;


typedef struct
{
    const char_t       test_description[64];         /* Test case description */
    void         (*test_function)(void);            /* Function pointer to execute the test case */
    test_input_t test_input;                /* Input argument */
    const char_t       *expected_result;          /* NULL if test does not output anything */
} test_case_t;

/**********************************************************************
 * @brief Structure to define a test.
 **********************************************************************/
typedef struct
{
    test_case_t test_case_list[10];
    char_t      test_name[64];
    uint32_t    test_case_count;
    uint8_t     padding[12];
} test_t;


/**********************************************************************
 * @brief Print a string to the console for the framework only
 *
 * @param str The string to be printed.
 * @return None.
 **********************************************************************/
extern void libtest_print_str(const char_t *str);
extern void libtest_memcpy(ptr_t dest, cptr_t src, const size_t size);

extern void libtest_start(const test_t *test);
extern void libtest_run(const test_t *test);
extern void libtest_finish(const test_t *test);

extern test_t g_test;

#endif /* __LIB_TEST_H__ */
