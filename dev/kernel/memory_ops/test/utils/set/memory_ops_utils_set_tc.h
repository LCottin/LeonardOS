#ifndef __MEMORY_OPS_UTILS_SET_TC_H__
#define __MEMORY_OPS_UTILS_SET_TC_H__

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
    byte_t  fill_byte;           /* Initial byte value used to fill the buffer before test */
    byte_t  reserved[3];         /* Reserved for future use, set to 0 */
    int32_t data_value;          /* Value used to set the buffer */
    size_t  buf_size;            /* Buffer size */
    size_t  buf_offset;          /* Offset in source buffer */
} memory_ops_utils_set_input_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char                      *name;
    memory_ops_utils_set_input_t     input;
} memory_ops_utils_set_tc_t;


/******************************************************************
 * @brief Test case functions
 ******************************************************************/
extern const char  *tc_name(size_t idx);
extern void         setup(const uint32_t idx);
extern void         run(const uint32_t idx);
extern void         check(const uint32_t idx);


/******************************************************************
 * @brief Test case data
 ******************************************************************/
extern const memory_ops_utils_set_tc_t  test_list[];
extern const spec_run_suite_t           test_suite;


#endif /* __MEMORY_OPS_UTILS_SET_TC_H__ */
