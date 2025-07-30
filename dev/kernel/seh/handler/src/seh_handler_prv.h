#ifndef __SEH_HANDLER_PRV_H__
#define __SEH_HANDLER_PRV_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Interruption type definitions for SEH.
 * ********************************************************************/
typedef enum
{
    SEH_EXCEPTION_FIQ,
    SEH_EXCEPTION_IRQ,
    SEH_EXCEPTION_SERR,
    SEH_EXCEPTION_SYNC,
    SEH_EXCEPTION_NB,
} seh_exception_type_t;


/**********************************************************************
 * @brief Generic handler called by all specific handlers.
 *
 * @param reg_lr Address of the link register
 * @param reg_esr Address of the exception syndrome register
 * @param interrupt_type Type of the interruption
 * @return None.
 **********************************************************************/
extern void seh_handler(const reg_t reg_lr, const reg_t reg_esr, const seh_exception_type_t interrupt_type);


#endif /* __SEH_HANDLER_PRV_H__ */
