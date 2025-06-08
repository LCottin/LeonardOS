#include "pcb_ctx.h"
#include "pcb_state.h"

void pcb_state_set_register(const uint32_t task_id, const pcb_state_registers_e reg_id, const reg_t new_value)
{
    /* Set the register value for the PCB context of the given task ID */
    if (task_id < g_pcb_ctx_table.pcb_apps_count)
    {
        switch (reg_id)
        {
            case PCB_STATE_REGISTER_R19:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r19 = new_value;
                break;
            case PCB_STATE_REGISTER_R20:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r20 = new_value;
                break;
            case PCB_STATE_REGISTER_R21:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r21 = new_value;
                break;
            case PCB_STATE_REGISTER_R22:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r22 = new_value;
                break;
            case PCB_STATE_REGISTER_R23:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r23 = new_value;
                break;
            case PCB_STATE_REGISTER_R24:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r24 = new_value;
                break;
            case PCB_STATE_REGISTER_R25:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r25 = new_value;
                break;
            case PCB_STATE_REGISTER_R26:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r26 = new_value;
                break;
            case PCB_STATE_REGISTER_R27:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r27 = new_value;
                break;
            case PCB_STATE_REGISTER_R28:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.r28 = new_value;
                break;
            case PCB_STATE_REGISTER_SP:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.sp = new_value;
                break;
            case PCB_STATE_REGISTER_LR:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.lr = new_value;
                break;
            case PCB_STATE_REGISTER_PC:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.pc = new_value;
                break;
            case PCB_STATE_REGISTER_CPSR:
                g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.cpsr = new_value;
                break;
            default:
                /* Invalid register ID, nothing to do */
                break;
        }
    }
    else
    {
        /* Invalid task ID, nothing to do */
    }
}
