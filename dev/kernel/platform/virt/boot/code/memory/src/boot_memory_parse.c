#include "boot_memory_prv.h"
#include "boot_memory.h"
#include "types_usr.h"
#include "bmt_krn.h"
#include "printer_krn.h"

void boot_memory_parse(void)
{
    addr_t current_addr    = K_BOOT_MEMORY_START_ADDR;
    const addr_t stop_addr = K_BOOT_MEMORY_STOP_ADDR;

    printer_print_string("[BOOT] Parsing memory for ELF ... \r\n");
    while (current_addr <= stop_addr)
    {
        const bool_t is_elf = elf_check_match_magic(current_addr);

        if (is_elf == TRUE)
        {
            printer_print_formatted("\tFound ELF at %x\r\n", current_addr);
            bmt_build_add_elf(current_addr);
        }
        else
        {
            /* Not an ELF, nothing to do */
        }

        current_addr += K_BOOT_MEMORY_STEP_SIZE;
    }

    printer_print_string("[BOOT] Done parsing memory for ELF\r\n\n");
}
