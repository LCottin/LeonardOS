#include "kernel_print.h"
#include "string_ops.h"
#include "string_utils.h"
#include "memory_ops.h"
#include "memory_alloc.h"

extern addr_t __stack_start;
extern addr_t __stack_end;
extern addr_t __stack_size;
extern addr_t __heap_start;
extern addr_t __heap_end;
extern addr_t __heap_size;
extern addr_t __bss_start;
extern addr_t __bss_end;
extern addr_t __data_start;
extern addr_t __data_end;
extern addr_t __text_start;
extern addr_t __text_end;
extern addr_t __rodata_start;
extern addr_t __rodata_end;

void main(void)
{
    memory_init_heap();

    const char_t str[64] = "[MAIN] Hello World!\n";

    kernel_print_string(str);

    char_t *ptr_alloc = (char_t *)memory_alloc_and_init(sizeof(char_t) * 64, 0);
    if (ptr_alloc != NULL)
    {
        memory_ops_copy(ptr_alloc, "[MAIN] Hello World from allocated buffer!\n", 64);
        kernel_print_string(ptr_alloc);
        memory_free(ptr_alloc);
    }
    else
    {
        kernel_print_string("[MAIN] Allocate memory failed\n");
    }

    char_t str_2[64];

    kernel_print_string("_text_start =   0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__text_start, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_text_end =     0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__text_end, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_rodata_start = 0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__rodata_start, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_rodata_end =   0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__rodata_end, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_data_start =   0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__data_start, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_data_end =     0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__data_end, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_bss_start =    0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__bss_start, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_bss_end =      0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__bss_end, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_stack_start =  0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__stack_start, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_stack_end =    0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__stack_end, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_stack_size =   0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__stack_size, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_heap_start =   0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__heap_start, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_heap_end =     0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__heap_end, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("_heap_size =    0x");
    kernel_print_string(string_utils_itoa((uint64_t)&__heap_size, str_2, 16U));
    kernel_print_string("\n");
    memory_ops_set(str_2, 0, sizeof(str_2));

    kernel_print_string("Sizeof(int) = ");
    kernel_print_string(string_utils_itoa(sizeof(int), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("Sizeof(short) = ");
    kernel_print_string(string_utils_itoa(sizeof(short), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("Sizeof(long long) = ");
    kernel_print_string(string_utils_itoa(sizeof(long long), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("Sizeof(long) = ");
    kernel_print_string(string_utils_itoa(sizeof(long), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("Sizeof(float) = ");
    kernel_print_string(string_utils_itoa(sizeof(float), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("Sizeof(double) = ");
    kernel_print_string(string_utils_itoa(sizeof(double), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("Sizeof(void *) = ");
    kernel_print_string(string_utils_itoa(sizeof(void *), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("Sizeof(char) = ");
    kernel_print_string(string_utils_itoa(sizeof(char), str_2, 10U));
    kernel_print_string("\n");

    kernel_print_string("[MAIN] Going to infinite loop ... ");
    while(1) ;
}
