#include "syscall_manager_tc.h"

const syscall_manager_tc_t test_list[] =
{
    [0] =
    {
        .name  = "TC-SYSCALL-MANAGER-001: SYSCALL_PRINT_STRING forwards the input buffer pointer unchanged",
        .input =
        {
            .syscall_id        = SYSCALL_PRINT_STRING,
            .string_value      = "Hello, world!",
            .current_task_idx  = 2U,
            .app_ctx_return    = 0x1000U
        },
        .expected =
        {
            .final_app_ctx              = 0x1000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 1U,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,

            /* Not used for this test */
            .print_signed_value         = 0,
            .print_signed_base          = 0,
            .print_address              = 0,
            .print_char                 = 0,
        }
    },
    [1] =
    {
        .name  = "TC-SYSCALL-MANAGER-002: SYSCALL_PRINT_INT forwards a negative value with base 10",
        .input =
        {
            .syscall_id        = SYSCALL_PRINT_INT,
            .int_value         = -42,
            .int_base          = 10U,
            .current_task_idx  = 5U,
            .app_ctx_return    = 0x2000U
        },
        .expected =
        {
            .final_app_ctx              = 0x2000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 1U,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,
            .print_signed_value         = -42,
            .print_signed_base          = STRINGS_UTILS_BASE_DECIMAL,

            /* Not used for this test */
            .print_address              = 0,
            .print_char                 = 0,
        }
    },
    [2] =
    {
        .name  = "TC-SYSCALL-MANAGER-003: SYSCALL_PRINT_INT forwards a positive value with base 16",
        .input =
        {
            .syscall_id        = SYSCALL_PRINT_INT,
            .int_value         = 123456,
            .int_base          = 16U,
            .current_task_idx  = 1U,
            .app_ctx_return    = 0x3000U
        },
        .expected =
        {
            .final_app_ctx              = 0x3000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 1U,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,
            .print_signed_value         = 123456,
            .print_signed_base          = STRINGS_UTILS_BASE_HEXADECIMAL,

            /* Not used for this test */
            .print_address              = 0,
            .print_char                 = 0,
        }
    },
    [3] =
    {
        .name  = "TC-SYSCALL-MANAGER-004: SYSCALL_PRINT_ADDR forwards the dereferenced address",
        .input =
        {
            .syscall_id        = SYSCALL_PRINT_ADDR,
            .addr_value        = 0xDEADBEEFU,
            .current_task_idx  = 7U,
            .app_ctx_return    = 0x4000U
        },
        .expected =
        {
            .final_app_ctx = 0x4000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 1U,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,
            .print_address = 0xDEADBEEFU,

            /* Not used for this test */
            .print_signed_base          = STRINGS_UTILS_BASE_HEXADECIMAL,
            .print_signed_value         = 0,
            .print_char                 = 0,
        }
    },
    [4] =
    {
        .name  = "TC-SYSCALL-MANAGER-005: SYSCALL_PRINT_CHAR forwards a typical printable character",
        .input =
        {
            .syscall_id        = SYSCALL_PRINT_CHAR,
            .char_value        = 'Q',
            .current_task_idx  = 0U,
            .app_ctx_return    = 0x5000U
        },
        .expected =
        {
            .final_app_ctx              = 0x5000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 1U,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,
            .print_char                 = 'Q',

            /* Not used for this test */
            .print_signed_value         = 0,
            .print_signed_base          = 0,
            .print_address              = 0,
        }
    },
    [5] =
    {
        .name  = "TC-SYSCALL-MANAGER-006: SYSCALL_PRINT_CHAR forwards a high-bit byte, exercising char_t signedness",
        .input =
        {
            .syscall_id        = SYSCALL_PRINT_CHAR,
            .char_value        = (char_t)0xFF,
            .current_task_idx  = 9U,
            .app_ctx_return    = 0x6000U
        },
        .expected =
        {
            .final_app_ctx              = 0x6000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 1U,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,
            .print_char                 = (char_t)0xFF,

            /* Not used for this test */
            .print_signed_value         = 0,
            .print_signed_base          = 0,
            .print_address              = 0,
        }
    },
    [6] =
    {
        .name  = "TC-SYSCALL-MANAGER-007: SYSCALL_GET_TIME copies the clock value to output.buffer but does NOT set output.size",
        .input =
        {
            .syscall_id        = SYSCALL_GET_TIME,
            .clock_time_return = 123456789012345ULL,
            .current_task_idx  = 4U,
            .app_ctx_return    = 0x7000U
        },
        .expected =
        {
            .final_app_ctx              = 0x7000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 1U,
            .nb_call_memory_copy        = 1U,
            .nb_call_console_pop        = 0,

            /* Not used for this test */
            .print_signed_value         = 0,
            .print_signed_base          = 0,
            .print_address              = 0,
            .print_char                 = 0,
        }
    },
    [7] =
    {
        .name  = "TC-SYSCALL-MANAGER-008: SYSCALL_YIELD overrides app_ctx with the next task's context",
        .input =
        {
            .syscall_id           = SYSCALL_YIELD,
            .current_task_idx     = 6U,
            .app_ctx_return       = 0x8000U,
            .next_task_ctx_return = 0x9000U
        },
        .expected =
        {
            .final_app_ctx              = 0x9000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 1U,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,

            /* Not used for this test */
            .print_signed_value         = 0,
            .print_signed_base          = 0,
            .print_address              = 0,
            .print_char                 = 0,
        }
    },
    [8] =
    {
        .name  = "TC-SYSCALL-MANAGER-009: SYSCALL_CONSOLE_GET copies the popped byte to output.buffer AND sets output.size",
        .input =
        {
            .syscall_id         = SYSCALL_CONSOLE_GET,
            .console_pop_return = 'Z',
            .current_task_idx   = 3U,
            .app_ctx_return     = 0xA000U
        },
        .expected =
        {
            .final_app_ctx              = 0xA000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 1U,
            .nb_call_console_pop        = 1U,

            /* Not used for this test */
            .print_signed_value         = 0,
            .print_signed_base          = 0,
            .print_address              = 0,
            .print_char                 = 0,
        }
    },
    [9] =
    {
        .name  = "TC-SYSCALL-MANAGER-010: Unknown syscall_id hits the default case - no handler runs, app_ctx passes through untouched",
        .input =
        {
            .syscall_id        = 9999U,
            .current_task_idx  = 8U,
            .app_ctx_return    = 0xB000U
        },
        .expected =
        {
            .final_app_ctx              = 0xB000U,
            .nb_call_get_current_task   = 1U,
            .nb_call_get_app_ctx        = 1U,
            .nb_call_switch_next_task   = 0,
            .nb_call_print_string       = 0,
            .nb_call_print_signed       = 0,
            .nb_call_print_address      = 0,
            .nb_call_print_char         = 0,
            .nb_call_get_time           = 0,
            .nb_call_memory_copy        = 0,
            .nb_call_console_pop        = 0,

            /* Not used for this test */
            .print_signed_value         = 0,
            .print_signed_base          = 0,
            .print_address              = 0,
            .print_char                 = 0,
        }
    },
};

const spec_run_suite_t test_suite =
{
    .suite_name = "syscall_manager",
    .tc_name    = tc_name,
    .setup      = setup,
    .run        = run,
    .check      = check,
    .tc_count   = sizeof(test_list)/sizeof(test_list[0])
};
