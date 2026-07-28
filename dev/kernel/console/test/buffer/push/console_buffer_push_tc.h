#ifndef __CONSOLE_BUFFER_PUSH_TC_H__
#define __CONSOLE_BUFFER_PUSH_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    char_t input_byte;                 /* Character passed to console_buffer_push() */
    byte_t reserved[3];                /* Reserved for future use */
} console_buffer_push_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    uint32_t nb_call_rb_push;            /* Expected number of calls to containers_ring_buffer_push() */
    char_t   output_byte;                /* Expected element value observed by containers_ring_buffer_push() */
    byte_t   reserved[3];                /* Reserved for future use */
} console_buffer_push_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                       *name;
    console_buffer_push_input_t         input;
    byte_t                              reserved[4];     /* Reserved for future use */
    console_buffer_push_output_t        expected;
} console_buffer_push_tc_t;


/******************************************************************
 * @brief Test case functions
 ******************************************************************/
extern const char_t *tc_name(const uint32_t idx);
extern void          setup(const uint32_t idx);
extern void          run(void);
extern void          check(void);


/******************************************************************
 * @brief Test case data
 ******************************************************************/
extern const console_buffer_push_tc_t  test_list[];
extern const spec_run_suite_t          test_suite;


#endif /* __CONSOLE_BUFFER_PUSH_TC_H__ */
