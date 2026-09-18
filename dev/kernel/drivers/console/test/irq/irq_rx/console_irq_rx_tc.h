#ifndef __CONSOLE_IRQ_RX_TC_H__
#define __CONSOLE_IRQ_RX_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    char_t input_byte;                 /* Byte returned by the mocked uart_read_byte() */
    byte_t reserved[3];                /* Reserved for future use */
} console_irq_rx_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    uint32_t nb_call_uart_read;          /* Expected number of calls to uart_read_byte() */
    uint32_t nb_call_buffer_push;        /* Expected number of calls to console_buffer_push() */
    char_t   pushed_byte;                /* Expected byte observed by console_buffer_push() */
    byte_t   reserved[3];                /* Reserved for future use */
} console_irq_rx_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                  *name;
    console_irq_rx_input_t         input;
    console_irq_rx_output_t        expected;
} console_irq_rx_tc_t;


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
extern const console_irq_rx_tc_t  test_list[];
extern const spec_run_suite_t     test_suite;
extern char_t uart_read_byte(void);


#endif /* __CONSOLE_IRQ_RX_TC_H__ */
