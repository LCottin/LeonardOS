#include "libuser_usr.h"
#include "syscall_krn.h"
#include "memory_krn.h"
#include "printer_usr.h"

void user_print_int(const int32_t num, const printer_base_t base)
{
    /* Allocate memory to use syscall */
    int32_t *p_num = (int32_t *)memory_alloc(sizeof(int32_t));
    printer_base_t *p_base = (printer_base_t *)memory_alloc(sizeof(printer_base_t));

    if ((p_num != NULL_PTR) && (p_base != NULL_PTR))
    {
        *p_base = base;
        *p_num  = num;

        /* Call syscall function */
        syscall_handler(SYSCALL_PRINT_INT, (cptr_t)p_num, (cptr_t)p_base, NULL_PTR);
    }

    /* Free allocated memory */
    memory_free((ptr_t)p_num);
    memory_free((ptr_t)p_base);
}
