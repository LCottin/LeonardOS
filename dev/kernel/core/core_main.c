#include "serial.h"
#include "string_ops.h"
#include "string_utils.h"
#include "memory_ops.h"
#include "memory_alloc.h"
#include "FPU.h"
#include "clock.h"

void core_main(void)
{
    memory_init_heap();
    FPU_init();
    clock_init();

    const char_t str[64] = "\n[MAIN] Hello World!\n";
    char_t str2[64];

    serial_print_string(str);

    char_t *ptr_alloc = (char_t *)memory_alloc_and_init(sizeof(char_t) * 64, 0);
    if (ptr_alloc != NULL)
    {
        memory_ops_copy(ptr_alloc, "\n[MAIN] Hello World from allocated buffer!\n", 64);
        serial_print_string(ptr_alloc);
        memory_free(ptr_alloc);
    }
    else
    {
        serial_print_string("\n[MAIN] Allocate memory failed\n");
    }

    serial_print_string("\n[MAIN] Current elapsed time (ns) : ");
    serial_print_string(string_utils_itoa((int32_t)clock_get_time(), str2, 10U));

    serial_print_string("\n[MAIN] Going to infinite loop ... ");
    while(1) ;
}
