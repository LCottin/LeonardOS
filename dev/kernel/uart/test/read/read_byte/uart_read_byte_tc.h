#ifndef __UART_READ_BYTE_TC_H__
#define __UART_READ_BYTE_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    char_t input_byte;                 /* Input byte to print */
    byte_t reserved[3];                /* Reserved for future use */
} uart_read_byte_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    uint32_t nb_call_mmio_read;          /* Number of calls to mmio_read */
    char_t   output_byte;                 /* Output byte printed */
    byte_t   reserved[3];                 /* Reserved for future use */
    addr_t   uart_addr;                   /* Address of the UART device */
} uart_read_byte_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char                      *name;
    uart_read_byte_input_t           input;
    byte_t                           reserved[4];     /* Reserved for future use */
    uart_read_byte_output_t          expected;
} uart_read_byte_tc_t;


/******************************************************************
 * @brief Test case functions
 ******************************************************************/
extern const char  *tc_name(size_t idx);
extern void         setup(const uint32_t idx);
extern void         run(void);
extern void         check(void);


/******************************************************************
 * @brief Test case data
 ******************************************************************/
extern const uart_read_byte_tc_t      test_list[];
extern const spec_run_suite_t         test_suite;
extern byte_t mmio_io8_read(cptr_t addr);


#endif /* __UART_READ_BYTE_TC_H__ */
