#include "kernelPrint.h"
#include "string.h"
#include "stdlib.h"

void main(void)
{
    const char str[64] = "[MAIN] Hello World!\n";
    char str_2[64];

    kernelPrint(str);

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
