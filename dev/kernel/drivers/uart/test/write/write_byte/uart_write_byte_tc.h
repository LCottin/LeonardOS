#ifndef __UART_WRITE_BYTE_TC_H__
#define __UART_WRITE_BYTE_TC_H__

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
} uart_write_byte_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    uint32_t nb_call_mmio_write;          /* Number of calls to mmio_write */
    char_t   output_byte;                 /* Output byte printed */
    byte_t   reserved[3];                 /* Reserved for future use */
    addr_t   uart_addr;                   /* Address of the UART device */
} uart_write_byte_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char                      *name;
    uart_write_byte_input_t          input;
    byte_t                           reserved[4];     /* Reserved for future use */
    uart_write_byte_output_t         expected;
} uart_write_byte_tc_t;


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
extern const uart_write_byte_tc_t      test_list[];
extern const spec_run_suite_t          test_suite;
extern void mmio_io8_write(ptr_t addr, const uint8_t value);


#endif /* __UART_WRITE_BYTE_TC_H__ */
