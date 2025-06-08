#ifndef __PCB_STATE_H__
#define __PCB_STATE_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Structure of PCB registers.
 **********************************************************************/
typedef struct
{
    volatile reg_t r19;     /* General purpose register callee-saved r19 */
    volatile reg_t r20;     /* General purpose register callee-saved r20 */
    volatile reg_t r21;     /* General purpose register callee-saved r21 */
    volatile reg_t r22;     /* General purpose register callee-saved r22 */
    volatile reg_t r23;     /* General purpose register callee-saved r23 */
    volatile reg_t r24;     /* General purpose register callee-saved r24 */
    volatile reg_t r25;     /* General purpose register callee-saved r25 */
    volatile reg_t r26;     /* General purpose register callee-saved r26 */
    volatile reg_t r27;     /* General purpose register callee-saved r27 */
    volatile reg_t r28;     /* General purpose register callee-saved r28 */
    volatile reg_t sp;      /* Stack pointer, equal to r29 */
    volatile reg_t lr;      /* Link register, equal to r30 */
    volatile reg_t pc;      /* Program counter */
    volatile reg_t cpsr;    /* Current program status register */
} pcb_state_registers_t;


/**********************************************************************
 * @brief Enumeration of PCB registers.
 **********************************************************************/
typedef enum
{
    PCB_STATE_REGISTER_R19,      /* Register r19 */
    PCB_STATE_REGISTER_R20,      /* Register r20 */
    PCB_STATE_REGISTER_R21,      /* Register r21 */
    PCB_STATE_REGISTER_R22,      /* Register r22 */
    PCB_STATE_REGISTER_R23,      /* Register r23 */
    PCB_STATE_REGISTER_R24,      /* Register r24 */
    PCB_STATE_REGISTER_R25,      /* Register r25 */
    PCB_STATE_REGISTER_R26,      /* Register r26 */
    PCB_STATE_REGISTER_R27,      /* Register r27 */
    PCB_STATE_REGISTER_R28,      /* Register r28 */
    PCB_STATE_REGISTER_SP,       /* Stack pointer (r29) */
    PCB_STATE_REGISTER_LR,       /* Link register (r30) */
    PCB_STATE_REGISTER_PC,       /* Program counter */
    PCB_STATE_REGISTER_CPSR      /* Current program status register */
} pcb_state_registers_e;


/**********************************************************************
 * @brief Set the state of a given task id
 *
 * @param task_id The ID of the task to set the state for.
 * @param new_state The new state to set for the task.
 * @return None.
 **********************************************************************/
extern void pcb_state_set_state(const uint32_t task_id, const pcb_states_t new_state);


/**********************************************************************
 * @brief Set the register value of a given task id
 *
 * @param task_id The ID of the task to set the state for.
 * @param reg_id The register ID to set.
 * @param new_value The new value to set for the register.
 * @return None.
 **********************************************************************/
extern void pcb_state_set_register(const uint32_t task_id, const pcb_state_registers_e reg_id, const reg_t new_value);


#endif /* __PCB_STATE_H__ */
