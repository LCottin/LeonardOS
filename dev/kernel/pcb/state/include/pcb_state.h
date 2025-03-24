#ifndef __PCB_STATE_H__
#define __PCB_STATE_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Enumeration of PCB states.
 **********************************************************************/
typedef enum
{
    PCB_STATE_NEW,              /* New PCB */
    PCB_STATE_READY,            /* Ready PCB */
    PCB_STATE_RUNNING,          /* Running PCB */
    PCB_STATE_BLOCKED,          /* Blocked PCB */
    PCB_STATE_SUSPENDED,        /* Suspended PCB */
    PCB_STATE_TERMINATED        /* Terminated PCB */
} pcb_states_t;


/**********************************************************************
 * @brief Structure of PCB registers.
 **********************************************************************/
typedef struct
{
    volatile reg_t r0;      /* General purpose register r0 */
    volatile reg_t r1;      /* General purpose register r1 */
    volatile reg_t r2;      /* General purpose register r2 */
    volatile reg_t r3;      /* General purpose register r3 */
    volatile reg_t r4;      /* General purpose register r4 */
    volatile reg_t r5;      /* General purpose register r5 */
    volatile reg_t r6;      /* General purpose register r6 */
    volatile reg_t r7;      /* General purpose register r7 */
    volatile reg_t r8;      /* General purpose register r8 */
    volatile reg_t r9;      /* General purpose register r9 */
    volatile reg_t r10;     /* General purpose register r10 */
    volatile reg_t r11;     /* General purpose register r11 */
    volatile reg_t r12;     /* General purpose register r12 */
    volatile reg_t r13;     /* General purpose register r13 */
    volatile reg_t r14;     /* General purpose register r14 */
    volatile reg_t r15;     /* General purpose register r15 */
    volatile reg_t r16;     /* General purpose register r16 */
    volatile reg_t r17;     /* General purpose register r17 */
    volatile reg_t r18;     /* General purpose register r18 */
    volatile reg_t r19;     /* General purpose register r19 */
    volatile reg_t r20;     /* General purpose register r20 */
    volatile reg_t r21;     /* General purpose register r21 */
    volatile reg_t r22;     /* General purpose register r22 */
    volatile reg_t r23;     /* General purpose register r23 */
    volatile reg_t r24;     /* General purpose register r24 */
    volatile reg_t r25;     /* General purpose register r25 */
    volatile reg_t r26;     /* General purpose register r26 */
    volatile reg_t r27;     /* General purpose register r27 */
    volatile reg_t r28;     /* General purpose register r28 */
    volatile reg_t r29;     /* General purpose register r29 */
    volatile reg_t r30;     /* General purpose register r30 */
    volatile reg_t sp;      /* Stack pointer */
    volatile reg_t lr;      /* Link register */
    volatile reg_t pc;      /* Program counter */
    volatile reg_t cpsr;    /* Current program status register */
} pcb_state_registers_t;


#endif /* __PCB_STATE_H__ */
