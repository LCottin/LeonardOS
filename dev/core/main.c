#include "kernelPrint.h"

void main(void)
{
    const char str[64] = "[MAIN] Hello World!\n";
    kernelPrint(str);

    kernelPrint("[MAIN] Going to infinite loop ... ");
    while(1) ;
}
