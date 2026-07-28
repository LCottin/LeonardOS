#ifndef __CONSOLE_BUFFER_IS_EMPTY_TC_H__
#define __CONSOLE_BUFFER_IS_EMPTY_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"
#include "containers_ring_buffer_usr.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    bool_t rb_is_empty;                  /* Value the mock containers_ring_buffer_is_empty() returns */
    byte_t reserved[4];                  /* Reserved for future use */
} console_buffer_is_empty_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    bool_t   is_empty;                   /* Expected return value of console_buffer_is_empty() */
    uint32_t nb_call_rb_is_empty;        /* Expected number of calls to containers_ring_buffer_is_empty() */
} console_buffer_is_empty_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                          *name;
    console_buffer_is_empty_input_t        input;
    console_buffer_is_empty_output_t       expected;
} console_buffer_is_empty_tc_t;


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
extern const console_buffer_is_empty_tc_t  test_list[];
extern const spec_run_suite_t              test_suite;
extern bool_t containers_ring_buffer_is_empty(const ring_buffer_t *rb);


#endif /* __CONSOLE_BUFFER_IS_EMPTY_TC_H__ */
