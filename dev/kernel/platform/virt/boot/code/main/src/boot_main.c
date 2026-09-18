#include "bmt_krn.h"
#include "printer_krn.h"
#include "boot_memory.h"
#include "arch_krn.h"
#include "boot_main_prv.h"

void boot_main(void)
{
    printer_print_string("\r\n[BOOT] Hello World!\r\n");

    bmt_ctx_init();
    boot_memory_parse();

    /* Build BMT */
    printer_print_string("[BOOT] Building BMT table...\r\n");
    bmt_build_table();
    bmt_info_print_table();

    /* Copies kernel and applications */
    printer_print_string("[BOOT] Copying binaries to RAM... ");
    bmt_build_copy_binaries();
    printer_print_string(" done\r\n");

    /* Launch kernel */
    const addr_t kernel_entry     = bmt_info_get_kernel_entry();
    const addr_t kernel_stack_top = bmt_info_get_kernel_stack_top();
    printer_print_string("[BOOT] Launching kernel ...\r\n");
    arch_entry_launch_kernel(kernel_entry, kernel_stack_top);
}
