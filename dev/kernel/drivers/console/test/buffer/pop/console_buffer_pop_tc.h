#ifndef __CONSOLE_BUFFER_POP_TC_H__
#define __CONSOLE_BUFFER_POP_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    bool_t  rb_is_empty;                 /* TRUE => mock containers_ring_buffer_pop() returns NULL_PTR */
    char_t  popped_byte;                 /* Byte the mock exposes via its returned pointer (ignored if rb_is_empty) */
    byte_t  reserved[3];                 /* Reserved for future use */
} console_buffer_pop_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    char_t   output_byte;                /* Expected return value of console_buffer_pop() */
    byte_t   reserved[3];                /* Reserved for future use */
    uint32_t nb_call_rb_pop;             /* Expected number of calls to containers_ring_buffer_pop() */
} console_buffer_pop_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                       *name;
    console_buffer_pop_input_t          input;
    console_buffer_pop_output_t         expected;
} console_buffer_pop_tc_t;


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
extern const console_buffer_pop_tc_t  test_list[];
extern const spec_run_suite_t         test_suite;


#endif /* __CONSOLE_BUFFER_POP_TC_H__ */
