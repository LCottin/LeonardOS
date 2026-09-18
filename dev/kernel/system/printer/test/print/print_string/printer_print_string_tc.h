#ifndef __PRINTER_PRINT_STRING_TC_H__
#define __PRINTER_PRINT_STRING_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"


/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    char_t  *str;                       /* String to print */
} printer_print_string_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    uint32_t    nb_call_uart;          /* Number of UART calls */
} printer_print_string_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char                      *name;
    printer_print_string_input_t     input;
    printer_print_string_output_t    output;
    byte_t                           reserved[4];        /* Reserved for future use */
} printer_print_string_tc_t;


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
extern const printer_print_string_tc_t  test_list[];
extern const spec_run_suite_t           test_suite;
extern void uart_write_byte(const uint8_t byte);

#endif /* __PRINTER_PRINT_STRING_TC_H__ */
