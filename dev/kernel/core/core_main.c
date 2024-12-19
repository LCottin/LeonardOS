#include "serial.h"
#include "string_ops.h"
#include "string_utils.h"
#include "memory_ops.h"
#include "memory_alloc.h"

void core_main(void)
{
    memory_init_heap();

    const char_t str[64] = "[MAIN] Hello World!\n";

    serial_print_string(str);

    char_t *ptr_alloc = (char_t *)memory_alloc_and_init(sizeof(char_t) * 64, 0);
    if (ptr_alloc != NULL)
    {
        memory_ops_copy(ptr_alloc, "[MAIN] Hello World from allocated buffer!\n", 64);
        serial_print_string(ptr_alloc);
        memory_free(ptr_alloc);
    }
    else
    {
        serial_print_string("[MAIN] Allocate memory failed\n");
    }

    serial_print_string("[MAIN] Going to infinite loop ... ");
    while(1) ;
}
