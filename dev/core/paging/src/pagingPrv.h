#ifndef __PAGING_PRV_H__
#define __PAGING_PRV_H__

#include "types.h"

#define PAGE_SIZE 4096           // 4KB page size
#define PAGE_TABLE_ENTRIES 512   // 512 entries per page table
#define PTE_VALID 0x1            // Valid entry
#define PTE_RW 0x2               // Read-write permissions
#define PTE_USER 0x4             // User-accessible
#define PTE_PAGE_SIZE_4KB 0x0    // 4KB page size

typedef uint64_t page_table_t[PAGE_TABLE_ENTRIES];

extern page_table_t l1_table;
extern page_table_t l2_table;
extern page_table_t l3_table;

extern void pagingEnableMmu(void);
extern void pagingMapPage(uint64_t *table, uint64_t virtual_addr, uint64_t physical_addr, uint64_t flags);

#endif /* __PAGING_PRV_H__ */
