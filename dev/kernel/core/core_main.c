#include "serial.h"
#include "string_ops.h"
#include "string_utils.h"
#include "memory_ops.h"
#include "memory.h"
#include "FPU.h"
#include "clock.h"
#include "core_main_prv.h"

void _core_entry(void)
{
    memory_init_heap();
    FPU_init();
    clock_init();

    const char_t str[64] = "\n[KERN] Hello World!\n";
    char_t str2[64];

    serial_print_string(str);

    char_t *ptr_alloc = (char_t *)memory_alloc_and_init(sizeof(char_t) * 64, 0);
    if (ptr_alloc != NULL)
    {
        memory_ops_copy(ptr_alloc, "[KERN] Hello World from allocated buffer!\n", 64);
        serial_print_string(ptr_alloc);
        memory_free(ptr_alloc);
    }
    else
    {
        serial_print_string("[KERN] Allocate memory failed\n");
    }

    serial_print_string("[KERN] Current elapsed time since startup: ");
    serial_print_string(string_utils_itoa((int32_t)clock_get_time(), str2, 10U));
    serial_print_string(" ns\n");

    serial_print_string("[KERN] Going to infinite loop ... ");
    while(1) ;
}
