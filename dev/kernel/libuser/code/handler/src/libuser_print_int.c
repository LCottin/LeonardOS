#include "libuser_usr.h"
#include "syscall_krn.h"
#include "memory_krn.h"
#include "printer_usr.h"

void user_print_int(const int32_t num, const printer_base_t base)
{
    int32_t value = num;
    printer_base_t base_raw = base;
    syscall_handler(SYSCALL_PRINT_INT, (cptr_t)&value, (cptr_t)&base_raw, NULL_PTR);
}
