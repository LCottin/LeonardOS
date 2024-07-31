#include "kernelPrint.h"

void memcpy(void *dest, const void *src, int size)
{
    unsigned char *d       = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    while(size--)
        *d++ = *s++;
}

void main(void)
{
    const char str[64] = "[MAIN] Hello World!\n";
    kernelPrint(str);

    kernelPrint("[MAIN] Going to infinite loop ... ");
    while(1) ;
}