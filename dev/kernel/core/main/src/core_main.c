#include "printer_krn.h"
#include "strings_ops_usr.h"
#include "strings_utils_usr.h"
#include "memory_ops_usr.h"
#include "memory_krn.h"
#include "fpu_krn.h"
#include "clock_krn.h"
#include "core_main_prv.h"
#include "pcb_krn.h"
#include "scheduler_krn.h"
#include "bmt_krn.h"

void _core_main_entry(const addr_t bmt_start_addr)
{
    const char_t str[64] = "\n[KERN] Hello World!\n";
    char_t str2[64];

    printer_print_string(str);

    bmt_ctx_init_kernel(bmt_start_addr);
    pcb_init();
    scheduler_init();
    memory_init_heap();
    fpu_init();

    char_t *ptr_alloc = (char_t *)memory_alloc_and_init(sizeof(char_t) * 64, 0);
    if (ptr_alloc != NULL)
    {
        memory_ops_copy(ptr_alloc, "[KERN] Hello World from allocated buffer!\n", 64);
        printer_print_string(ptr_alloc);
        memory_free(ptr_alloc);
    }
    else
    {
        printer_print_string("[KERN] Allocate memory failed\n");
    }

    printer_print_string("[KERN] Current elapsed time since startup: ");
    printer_print_string(string_utils_itoa((int32_t)clock_info_get_time(), str2, 10U));
    printer_print_string(" ns\n");

    printer_print_string("[KERN] Launching scheduling ... \n");

    /* Launch application scheduling */
    scheduler_run();

    /* Not reached */
}
