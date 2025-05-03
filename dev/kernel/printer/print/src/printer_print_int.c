#include "printer_krn.h"
#include "uart_krn.h"
#include "strings_utils_usr.h"

void printer_print_int(const int32_t value, const printer_base_t base)
{
    char_t buffer[16];
    string_utils_itoa(value, buffer, base);
    printer_print_string(buffer);
}
