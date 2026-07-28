#ifndef __CONTAINERS_RING_BUFFER_INIT_TC_H__
#define __CONTAINERS_RING_BUFFER_INIT_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"
#include "containers_ring_buffer_usr.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    size_t capacity;                    /* capacity passed to init() */
    size_t element_size;                /* element_size passed to init() */
    size_t dirty_size;                  /* Garbage pre-loaded into rb.size before init() */
    size_t dirty_head;                  /* Garbage pre-loaded into rb.head before init() */
    size_t dirty_tail;                  /* Garbage pre-loaded into rb.tail before init() */
} containers_ring_buffer_init_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    size_t capacity;                     /* Expected rb.capacity after init() */
    size_t element_size;                 /* Expected rb.element_size after init() */
    size_t size;                         /* Expected rb.size after init() (always 0) */
    size_t head;                         /* Expected rb.head after init() (always 0) */
    size_t tail;                         /* Expected rb.tail after init() (always 0) */
} containers_ring_buffer_init_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                            *name;
    containers_ring_buffer_init_input_t      input;
    containers_ring_buffer_init_output_t     expected;
} containers_ring_buffer_init_tc_t;


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
extern const containers_ring_buffer_init_tc_t  test_list[];
extern const spec_run_suite_t                  test_suite;


#endif /* __CONTAINERS_RING_BUFFER_INIT_TC_H__ */
