#ifndef __CONTAINERS_RING_BUFFER_PUSH_TC_H__
#define __CONTAINERS_RING_BUFFER_PUSH_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"
#include "containers_ring_buffer_usr.h"

#define RB_PUSH_TC_MAX_ELEMENT_BYTES 8U

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    size_t  capacity;                                /* rb.capacity before the call */
    size_t  element_size;                            /* rb.element_size before the call (<= RB_PUSH_TC_MAX_ELEMENT_BYTES) */
    size_t  size;                                    /* rb.size before the call */
    size_t  head;                                    /* rb.head before the call */
    size_t  tail;                                    /* rb.tail before the call */
    uint8_t elements[RB_PUSH_TC_MAX_ELEMENT_BYTES];  /* Elements bytes pushed (only the first element_size bytes matter) */
} containers_ring_buffer_push_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    size_t   head;                       /* Expected rb.head after push() */
    size_t   tail;                       /* Expected rb.tail after push() */
    size_t   size;                       /* Expected rb.size after push() */
    size_t   dest_offset;                /* Expected byte offset (in the backing buffer) written to */
    uint32_t nb_call_copy;               /* Expected number of calls to memory_ops_utils_copy() */
    size_t   copy_size;                  /* Expected "size" argument passed to memory_ops_utils_copy() */
} containers_ring_buffer_push_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                            *name;
    containers_ring_buffer_push_input_t      input;
    containers_ring_buffer_push_output_t     expected;
    byte_t                                   reserved[4]; /* Reserved for future use */
} containers_ring_buffer_push_tc_t;


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
extern const containers_ring_buffer_push_tc_t  test_list[];
extern const spec_run_suite_t                  test_suite;
extern void memory_ops_utils_copy(ptr_t dest, cptr_t src, const size_t size);


#endif /* __CONTAINERS_RING_BUFFER_PUSH_TC_H__ */
