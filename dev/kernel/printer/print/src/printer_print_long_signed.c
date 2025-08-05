#include "printer_krn.h"
#include "strings_utils_usr.h"

void printer_print_long_signed(const int64_t value, const printer_base_t base)
{
    char_t buffer[32];

    strings_utils_itoa(base, value, buffer);
    printer_print_string(buffer);
}
