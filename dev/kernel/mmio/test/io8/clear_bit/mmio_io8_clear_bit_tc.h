#ifndef __MMIO_IO8_CLEAR_BIT_TC_H__
#define __MMIO_IO8_CLEAR_BIT_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Maximum number of bits to clear in a single test case
 ******************************************************************/
#define K_MMIO_IO8_CLEAR_BIT_NB_BITS_MAX 8


/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    byte_t  init_byte;                                              /* byte value used to fill the buffer before test */
    uint8_t number_of_clears;                                       /* Number of bits to clear*/
    uint8_t bit_index_to_clear[K_MMIO_IO8_CLEAR_BIT_NB_BITS_MAX];   /* bit indexes to clear in the buffer */
} mmio_io8_clear_bit_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    byte_t expected_result;     /* Expected result */
} mmio_io8_clear_bit_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                  *name;
    mmio_io8_clear_bit_input_t     input;
    mmio_io8_clear_bit_output_t    expected;
    byte_t                         reserved[5];   /* Reserved for future use */
} mmio_io8_clear_bit_tc_t;


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
extern const mmio_io8_clear_bit_tc_t test_list[];
extern const spec_run_suite_t        test_suite;


#endif /* __MMIO_IO8_CLEAR_BIT_TC_H__ */
