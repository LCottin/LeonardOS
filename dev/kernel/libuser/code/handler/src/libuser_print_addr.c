#include "libuser_usr.h"
#include "syscall_krn.h"
#include "memory_krn.h"

void user_print_addr(const addr_t addr)
{
    /* Allocate memory to use syscall */
    addr_t *p_addr = (addr_t *)memory_alloc(sizeof(addr_t));
    *p_addr = addr;

    /* Call syscall function */
    syscall_handler(SYSCALL_PRINT_ADDR, (cptr_t)p_addr, NULL_PTR, NULL_PTR);

    /* Free allocated memory */
    memory_free((ptr_t)p_addr);
}
