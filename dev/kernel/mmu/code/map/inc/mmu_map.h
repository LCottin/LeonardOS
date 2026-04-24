#ifndef __MMU_MAP_H__
#define __MMU_MAP_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Page permission flags passed to mmu_map_page().
 *        Combine with bitwise OR.
 **********************************************************************/
#define MMU_PERM_R      (1U << 0U)   /* Readable                  */
#define MMU_PERM_W      (1U << 1U)   /* Writable                  */
#define MMU_PERM_X      (1U << 2U)   /* Executable                */
#define MMU_PERM_USER   (1U << 3U)   /* Accessible from EL0       */
#define MMU_PERM_DEVICE (1U << 4U)   /* Device / MMIO memory      */

/**********************************************************************
 * @brief Maps one 4KB virtual page to one physical frame in the
 *        kernel page tables (TTBR1 / EL1).
 *
 * Allocates intermediate table levels as needed from the page pool.
 * An identity mapping (va == pa) is used for the kernel during Phase 1.
 *
 * @param va    Virtual address (4KB aligned).
 * @param pa    Physical address (4KB aligned).
 * @param perms Permission flags (MMU_PERM_*).
 * @return TRUE on success, FALSE if a page could not be allocated.
 **********************************************************************/
extern bool_t mmu_map_page(const addr_t va, const addr_t pa, const uint32_t perms);

#endif /* __MMU_MAP_H__ */
