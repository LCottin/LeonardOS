#ifndef __MEMORY_OPS_UTILS_CMP_TC_H__
#define __MEMORY_OPS_UTILS_CMP_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case buffer size to compare
 ******************************************************************/
#define BUFFER_SIZE 128U


/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    byte_t init1_byte;           /* byte value used to fill the buffer 1 before test */
    byte_t init2_byte;           /* byte value used to fill the buffer 2 before test */
    byte_t fill1_byte;           /* byte value used to fill the buffer 1 before test */
    byte_t fill2_byte;           /* byte value used to fill the buffer 2 before test */
    size_t buf1_size;            /* buffer 1 size */
    size_t buf2_size;            /* buffer 2 size */
    size_t cmp_size;             /* number of bytes to compare */
} memory_ops_utils_cmp_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    int32_t comparison_result;   /* expected result of the comparison */
} memory_ops_utils_cmp_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char                      *name;
    memory_ops_utils_cmp_input_t     input;
    memory_ops_utils_cmp_output_t    expected;
    byte_t                           reserved[4]; /* Reserved for future use, set to 0 */
} memory_ops_utils_cmp_tc_t;


/******************************************************************
 * @brief Test case functions
 ******************************************************************/
extern const char  *tc_name(size_t idx);
extern void         setup(const uint32_t idx);
extern void         run(void);
extern void         check(void);


/******************************************************************
 * @brief Test case data
 ******************************************************************/
extern const memory_ops_utils_cmp_tc_t test_list[];
extern const spec_run_suite_t          test_suite;


#endif /* __MEMORY_OPS_UTILS_CMP_TC_H__ */
