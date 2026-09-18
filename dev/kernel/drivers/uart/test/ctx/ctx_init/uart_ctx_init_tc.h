#ifndef __UART_CTX_INIT_TC_H__
#define __UART_CTX_INIT_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"

/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    uint32_t    io32_read_cr_value;     /* CR_ADDR register value */
    uint8_t     io8_read_imsc_value;    /* IMSC_addr register value */
    uint8_t     reserved[3];            /* Reserved for future use */
} uart_ctx_init_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    addr_t cr_addr;                       /* CR register address */
    addr_t ismc_addr;                     /* IMSC register address */
    uint32_t cr_value;                    /* CR register value */
    uint8_t ismc_value;                   /* IMSC register value */
    uint8_t reserved[3];                  /* Reserved for future use */

    uint32_t nb_call_mmio_write32;          /* Number of calls to mmio_write32 */
    uint32_t nb_call_mmio_write8;           /* Number of calls to mmio_write8 */
    uint32_t nb_call_mmio_read32;           /* Number of calls to mmio_read32 */
    uint32_t nb_call_mmio_read8;            /* Number of calls to mmio_read8 */
} uart_ctx_init_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char                     *name;
    uart_ctx_init_input_t           input;
    uart_ctx_init_output_t          expected;
} uart_ctx_init_tc_t;


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
extern const    uart_ctx_init_tc_t test_list[];
extern const    spec_run_suite_t   test_suite;
extern void     mmio_io8_write(ptr_t addr, const uint8_t value);
extern void     mmio_io32_write(ptr_t addr, const uint32_t value);
extern uint32_t mmio_io32_read(cptr_t addr);
extern uint8_t  mmio_io8_read(cptr_t addr);


#endif /* __UART_CTX_INIT_TC_H__ */
