#include "kernelPrint.h"
#include "string.h"
#include "stdlib.h"
#include "memory.h"

extern unsigned long int __stack_start;
extern unsigned long int __stack_end;
extern unsigned long int __stack_size;
extern unsigned long int __bss_start;
extern unsigned long int __bss_end;
extern unsigned long int __data_start;
extern unsigned long int __data_end;
extern unsigned long int __text_start;
extern unsigned long int __text_end;
extern unsigned long int __rodata_start;
extern unsigned long int __rodata_end;

void main(void)
{
    const char str[64] = "[MAIN] Hello World!\n";

    kernelPrint(str);

    char str_2[64];

    kernelPrint("_text_start =   0x");
    kernelPrint(itoa((uint64_t)&__text_start, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_text_end =     0x");
    kernelPrint(itoa((uint64_t)&__text_end, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_rodata_start = 0x");
    kernelPrint(itoa((uint64_t)&__rodata_start, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_rodata_end =   0x");
    kernelPrint(itoa((uint64_t)&__rodata_end, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_data_start =   0x");
    kernelPrint(itoa((uint64_t)&__data_start, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_data_end =     0x");
    kernelPrint(itoa((uint64_t)&__data_end, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_bss_start =    0x");
    kernelPrint(itoa((uint64_t)&__bss_start, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_bss_end =      0x");
    kernelPrint(itoa((uint64_t)&__bss_end, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_stack_start =  0x");
    kernelPrint(itoa((uint64_t)&__stack_start, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_stack_end =    0x");
    kernelPrint(itoa((uint64_t)&__stack_end, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("_stack_size =   0x");
    kernelPrint(itoa((uint64_t)&__stack_size, str_2, 16U));
    kernelPrint("\n");
    memset(str_2, 0, sizeof(str_2));

    kernelPrint("Sizeof(int) = ");
    kernelPrint(itoa(sizeof(int), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("Sizeof(short) = ");
    kernelPrint(itoa(sizeof(short), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("Sizeof(long long) = ");
    kernelPrint(itoa(sizeof(long long), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("Sizeof(long) = ");
    kernelPrint(itoa(sizeof(long), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("Sizeof(float) = ");
    kernelPrint(itoa(sizeof(float), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("Sizeof(double) = ");
    kernelPrint(itoa(sizeof(double), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("Sizeof(void *) = ");
    kernelPrint(itoa(sizeof(void *), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("Sizeof(char) = ");
    kernelPrint(itoa(sizeof(char), str_2, 10U));
    kernelPrint("\n");

    kernelPrint("[MAIN] Going to infinite loop ... ");
    while(1) ;
}
