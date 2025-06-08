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


#endif /* __PCB_STATE_H__ */
