#ifndef __SYSCALL_MANAGER_TC_H__
#define __SYSCALL_MANAGER_TC_H__

#include "types_usr.h"
#include "spec_assert_krn.h"
#include "spec_run_krn.h"
#include "syscall_types.h"
#include "syscall_krn.h"

/******************************************************************
 * @brief Maximum size of the string to test
 ******************************************************************/
#define SYSCALL_MANAGER_TC_MAX_STR 32U


/******************************************************************
 * @brief Test case input structure
 ******************************************************************/
typedef struct
{
    syscall_numbers_e       syscall_id;                                     /* request->syscall_id under test (may be an out-of-range/unknown value) */
    int32_t                 int_value;                                      /* SYSCALL_PRINT_INT: value field of the syscall_print_int_t argument */
    strings_utils_base_t    int_base;                                       /* SYSCALL_PRINT_INT: base field of the syscall_print_int_t argument */
    uint32_t                current_task_idx;                               /* Value returned by the mocked scheduler_ctx_get_current_task() */
    addr_t                  addr_value;                                     /* SYSCALL_PRINT_ADDR: address exposed via input.buffer */
    reg_t                   app_ctx_return;                                 /* Value returned by the mocked scheduler_ctx_get_app_ctx() */
    reg_t                   next_task_ctx_return;                           /* SYSCALL_YIELD: value returned by the mocked scheduler_switch_next_task() */
    uint64_t                clock_time_return;                              /* SYSCALL_GET_TIME: value returned by the mocked clock_info_get_time() */
    char_t                  console_pop_return;                             /* SYSCALL_CONSOLE_GET: value returned by the mocked console_buffer_pop() */
    char_t                  string_value[SYSCALL_MANAGER_TC_MAX_STR];       /* SYSCALL_PRINT_STRING: NULL-terminated string exposed via input.buffer */
    char_t                  char_value;                                     /* SYSCALL_PRINT_CHAR: char exposed via input.buffer */
    byte_t                  reserved[6];                                    /* Reserved for future use */
} syscall_manager_input_t;


/******************************************************************
 * @brief Test case output structure
 ******************************************************************/
typedef struct
{
    reg_t                   final_app_ctx;                                  /* Expected return value of syscall_manager() */
    uint32_t                nb_call_get_current_task;                       /* Number of call to get_current_task() */
    uint32_t                nb_call_get_app_ctx;                            /* Number of call to get_app_ctx() */
    uint32_t                nb_call_switch_next_task;                       /* Number of call to switch_next_task() */
    uint32_t                nb_call_print_string;                           /* Number of call to print_string() */
    uint32_t                nb_call_print_signed;                           /* Number of call to print_signed() */
    uint32_t                nb_call_print_address;                          /* Number of call to print_address() */
    uint32_t                nb_call_print_char;                             /* Number of call to print_char() */
    uint32_t                nb_call_get_time;                               /* Number of call to get_time() */
    uint32_t                nb_call_memory_copy;                            /* Number of call to memory_copy() */
    uint32_t                nb_call_console_pop;                            /* Number of call to console_pop() */
    int32_t                 print_signed_value;                             /* Expected value forwarded to printer_print_signed() */
    uint32_t                print_signed_base;                              /* Expected base forwarded to printer_print_signed() */
    addr_t                  print_address;                                  /* Expected address forwarded to printer_print_address() */
    char_t                  print_char;                                     /* Expected char forwarded to printer_print_char() */
    byte_t                  reserved[7];                                    /* Reserved for future use */
} syscall_manager_output_t;


/******************************************************************
 * @brief Test case structure
 ******************************************************************/
typedef struct
{
    const char_t                *name;
    syscall_manager_input_t      input;
    syscall_manager_output_t     expected;
} syscall_manager_tc_t;


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
extern const syscall_manager_tc_t  test_list[];
extern const spec_run_suite_t      test_suite;


#endif /* __SYSCALL_MANAGER_TC_H__ */
