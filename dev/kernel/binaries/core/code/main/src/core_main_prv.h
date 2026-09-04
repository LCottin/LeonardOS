#ifndef __CORE_MAIN_PRV_H__
#define __CORE_MAIN_PRV_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Kernel entry point.
 *
 * @param bmt_start_addr Start address of the BMT region.
 * @param sch_start_addr Start address of the SCH region.
 * @return Does not return.
 **********************************************************************/
extern void _core_main_entry(const addr_t bmt_start_addr, const addr_t sch_start_addr);


#endif /* __CORE_MAIN_PRV_H__ */
