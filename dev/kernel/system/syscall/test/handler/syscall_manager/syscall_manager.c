#include "types_usr.h"
#include "spec_run_krn.h"
#include "spec_utils_krn.h"
#include "spec_assert_krn.h"
#include "syscall_manager_tc.h"
#include "syscall_krn.h"
#include "syscall_types.h"
#include "scheduler_krn.h"
#include "printer_krn.h"
#include "clock_krn.h"
#include "memory_ops_usr.h"
#include "console_krn.h"
#include "syscall_handler_prv.h"

static syscall_request_t        s_request;
static char_t                   s_input_string_backing[SYSCALL_MANAGER_TC_MAX_STR];
static syscall_print_int_t      s_input_int_backing;
static addr_t                   s_input_addr_backing;
static char_t                   s_input_char_backing;
static uint8_t                  s_output_backing[16];
static uint32_t                 s_nb_call_get_current_task;
static uint32_t                 s_nb_call_get_app_ctx;
static uint32_t                 s_nb_call_switch_next_task;
static uint32_t                 s_nb_call_print_string;
static uint32_t                 s_nb_call_print_signed;
static uint32_t                 s_nb_call_print_address;
static uint32_t                 s_nb_call_print_char;
static uint32_t                 s_nb_call_get_time;
static uint32_t                 s_nb_call_memory_copy;
static uint32_t                 s_nb_call_console_pop;
static syscall_manager_tc_t     s_tc;
static reg_t                    s_result;

const char_t *tc_name(const uint32_t idx)
{
    return test_list[idx].name;
}


/* ================================================================== */
/* Mocked dependencies                                                   */
/* ================================================================== */
uint32_t scheduler_ctx_get_current_task(void)
{
    s_nb_call_get_current_task++;

    return s_tc.input.current_task_idx;
}

reg_t scheduler_ctx_get_app_ctx(const uint32_t task_idx)
{
    SPEC_EXPECT_EQ_U32(task_idx, s_tc.input.current_task_idx);

    s_nb_call_get_app_ctx++;

    return s_tc.input.app_ctx_return;
}

reg_t scheduler_switch_next_task(void)
{
    s_nb_call_switch_next_task++;

    return s_tc.input.next_task_ctx_return;
}

void printer_print_string(const char_t *str)
{
    SPEC_EXPECT_EQ_PTR(str, (ptr_t)s_input_string_backing);

    s_nb_call_print_string++;
}

void printer_print_signed(const int32_t value, const uint32_t base)
{
    SPEC_EXPECT_EQ_U32(value, s_tc.expected.print_signed_value);
    SPEC_EXPECT_EQ_U32(base,  s_tc.expected.print_signed_base);

    s_nb_call_print_signed++;
}

void printer_print_address(const addr_t addr)
{
    SPEC_EXPECT_EQ_U64(addr, s_tc.expected.print_address);

    s_nb_call_print_address++;
}

void printer_print_char(const char_t c)
{
    SPEC_EXPECT_EQ_CHAR(c, s_tc.expected.print_char);

    s_nb_call_print_char++;
}

time_t clock_info_get_time(void)
{
    s_nb_call_get_time++;

    return (time_t)s_tc.input.clock_time_return;
}

ptr_t memory_ops_utils_copy(ptr_t dest, cptr_t src, const size_t size)
{
    SPEC_EXPECT_EQ_PTR(dest, (ptr_t)s_output_backing);

    spec_utils_memcpy(dest, src, size);

    s_nb_call_memory_copy++;

    return dest;
}

char_t console_buffer_pop(void)
{
    s_nb_call_console_pop++;

    return s_tc.input.console_pop_return;
}


/* ================================================================== */
/* Test case plumbing                                                    */
/* ================================================================== */
void setup(const uint32_t idx)
{
    /* Set current test data */
    spec_utils_memcpy(&s_tc, &test_list[idx], sizeof(s_tc));

    s_nb_call_get_current_task = 0U;
    s_nb_call_get_app_ctx      = 0U;
    s_nb_call_switch_next_task = 0U;
    s_nb_call_print_string     = 0U;
    s_nb_call_print_signed     = 0U;
    s_nb_call_print_address    = 0U;
    s_nb_call_print_char       = 0U;
    s_nb_call_get_time         = 0U;
    s_nb_call_memory_copy      = 0U;
    s_nb_call_console_pop      = 0U;

    spec_utils_memset(s_output_backing, 0, sizeof(s_output_backing));

    s_request.syscall_id    = s_tc.input.syscall_id;
    s_request.output.buffer = (ptr_t)s_output_backing;
    s_request.input.buffer  = NULL_PTR;

    switch (s_tc.input.syscall_id)
    {
        case SYSCALL_PRINT_STRING:
        {
            spec_utils_memcpy(s_input_string_backing, s_tc.input.string_value, sizeof(s_input_string_backing));
            s_request.input.buffer = (ptr_t)s_input_string_backing;
            break;
        }

        case SYSCALL_PRINT_INT:
        {
            s_input_int_backing.value = s_tc.input.int_value;
            s_input_int_backing.base  = s_tc.input.int_base;
            s_request.input.buffer    = (ptr_t)&s_input_int_backing;
            break;
        }

        case SYSCALL_PRINT_ADDR:
        {
            s_input_addr_backing   = s_tc.input.addr_value;
            s_request.input.buffer = (ptr_t)&s_input_addr_backing;
            break;
        }

        case SYSCALL_PRINT_CHAR:
        {
            s_input_char_backing   = s_tc.input.char_value;
            s_request.input.buffer = (ptr_t)&s_input_char_backing;
            break;
        }

        default:
        {
            /* SYSCALL_GET_TIME / SYSCALL_YIELD / SYSCALL_CONSOLE_GET / unknown ids
             * never read request->input.buffer. */
            break;
        }
    }

    s_result = ~s_tc.expected.final_app_ctx; /* sentinel, overwritten by run() */
}

void run(void)
{
    s_result = syscall_manager(&s_request);
}

void check(void)
{
    /* Check the returned app context */
    SPEC_EXPECT_EQ_U64(s_result, s_tc.expected.final_app_ctx);

    /* Check that every dependency was called (or not called) the expected number of times */
    SPEC_EXPECT_EQ_U32(s_nb_call_get_current_task, s_tc.expected.nb_call_get_current_task);
    SPEC_EXPECT_EQ_U32(s_nb_call_get_app_ctx,      s_tc.expected.nb_call_get_app_ctx);
    SPEC_EXPECT_EQ_U32(s_nb_call_switch_next_task, s_tc.expected.nb_call_switch_next_task);
    SPEC_EXPECT_EQ_U32(s_nb_call_print_string,     s_tc.expected.nb_call_print_string);
    SPEC_EXPECT_EQ_U32(s_nb_call_print_signed,     s_tc.expected.nb_call_print_signed);
    SPEC_EXPECT_EQ_U32(s_nb_call_print_address,    s_tc.expected.nb_call_print_address);
    SPEC_EXPECT_EQ_U32(s_nb_call_print_char,       s_tc.expected.nb_call_print_char);
    SPEC_EXPECT_EQ_U32(s_nb_call_get_time,         s_tc.expected.nb_call_get_time);
    SPEC_EXPECT_EQ_U32(s_nb_call_memory_copy,      s_tc.expected.nb_call_memory_copy);
    SPEC_EXPECT_EQ_U32(s_nb_call_console_pop,      s_tc.expected.nb_call_console_pop);

    /* Check the bytes actually written into request->output.buffer */
    if (s_tc.input.syscall_id == SYSCALL_GET_TIME)
    {
        const uint8_t *expected_bytes = (const uint8_t *)&s_tc.input.clock_time_return;

        for (size_t i = 0U; i < sizeof(time_t); i++)
        {
            SPEC_EXPECT_EQ_U8(s_output_backing[i], expected_bytes[i]);
        }
    }
    else if (s_tc.input.syscall_id == SYSCALL_CONSOLE_GET)
    {
        SPEC_EXPECT_EQ_CHAR((char_t)s_output_backing[0], s_tc.input.console_pop_return);
    }
    else
    {
        /* No other branch is expected to write to output.buffer */
    }
}


/* ================================================================== */
/* Entry point                                                          */
/* ================================================================== */
void test_suite_entry(void)
{
    spec_run_suite(&test_suite);

    while(1);
}
