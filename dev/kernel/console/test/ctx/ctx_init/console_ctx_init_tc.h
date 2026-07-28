#ifndef __CONSOLE_CTX_INIT_TC_H__
#define __CONSOLE_CTX_INIT_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    uint32_t call_count;                 /* Number of times console_ctx_init() is invoked during run() */
} console_ctx_init_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    size_t   expected_capacity;             /* Expected capacity argument passed to containers_ring_buffer_init() */
    size_t   expected_element_size;         /* Expected element_size argument passed to containers_ring_buffer_init() */
    uint32_t expected_irq_nb;               /* Expected irq number argument passed to irq_core_register() */
    uint32_t nb_call_rb_init;               /* Expected number of calls to containers_ring_buffer_init() */
    uint32_t nb_call_irq_register;          /* Expected number of calls to irq_core_register() */
} console_ctx_init_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                     *name;
    console_ctx_init_input_t          input;
    console_ctx_init_output_t         expected;
} console_ctx_init_tc_t;


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
extern const console_ctx_init_tc_t  test_list[];
extern const spec_run_suite_t       test_suite;


#endif /* __CONSOLE_CTX_INIT_TC_H__ */
