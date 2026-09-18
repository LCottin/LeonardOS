#ifndef __CONTAINERS_RING_BUFFER_POP_TC_H__
#define __CONTAINERS_RING_BUFFER_POP_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"
#include "containers_ring_buffer_usr.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    size_t capacity;                     /* rb.capacity before the call */
    size_t element_size;                 /* rb.element_size before the call */
    size_t size;                         /* rb.size before the call */
    size_t head;                         /* rb.head before the call */
    size_t tail;                         /* rb.tail before the call */
} containers_ring_buffer_pop_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    bool_t returns_null;                 /* TRUE if pop() is expected to return NULL_PTR (empty buffer) */
    byte_t reserved[4];                  /* Reserved for future use */
    size_t dest_offset;                  /* If returns_null == FALSE, expected byte offset of the returned pointer */
    size_t head;                         /* Expected rb.head after pop() */
    size_t tail;                         /* Expected rb.tail after pop() */
    size_t size;                         /* Expected rb.size after pop() */
} containers_ring_buffer_pop_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                          *name;
    containers_ring_buffer_pop_input_t     input;
    containers_ring_buffer_pop_output_t    expected;
    byte_t                                 reserved[4]; /* Reserved for future use */
} containers_ring_buffer_pop_tc_t;


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
extern const containers_ring_buffer_pop_tc_t  test_list[];
extern const spec_run_suite_t                 test_suite;


#endif /* __CONTAINERS_RING_BUFFER_POP_TC_H__ */
