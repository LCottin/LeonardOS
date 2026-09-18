#ifndef __MMIO_IO32_WRITE_TC_H__
#define __MMIO_IO32_WRITE_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    uint32_t  reg_value;          /* Value to initialize register */
    uint32_t  init_byte;          /* Value to initialize read value */
} mmio_io32_write_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    uint32_t expected_value;     /* Expected result */
} mmio_io32_write_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t              *name;
    mmio_io32_write_input_t    input;
    mmio_io32_write_output_t   expected;
    byte_t                     reserved[4];   /* Reserved for future use */
} mmio_io32_write_tc_t;


/******************************************************************
 * @brief Test case functions
 ******************************************************************/
extern const char_t  *tc_name(const size_t idx);
extern void           setup(const uint32_t idx);
extern void           run(void);
extern void           check(void);


/******************************************************************
 * @brief Test case data
 ******************************************************************/
extern const mmio_io32_write_tc_t test_list[];
extern const spec_run_suite_t     test_suite;


#endif /* __MMIO_IO32_READ_TC_H__ */
