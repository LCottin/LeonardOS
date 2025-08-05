#include "printer_krn.h"
#include "strings_utils_usr.h"

void printer_print_unsigned(const uint32_t value, const printer_base_t base)
{
    char_t buffer[16];

    strings_utils_utoa(base, (uint64_t)value, buffer);
    printer_print_string(buffer);
}
