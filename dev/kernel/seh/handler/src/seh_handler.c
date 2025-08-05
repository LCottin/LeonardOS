#include "seh_handler_prv.h"
#include "printer_krn.h"

static const char_t *g_seh_exception_messages[SEH_EXCEPTION_NB] =
{
    [SEH_EXCEPTION_FIQ]  = "FIQ exception",
    [SEH_EXCEPTION_IRQ]  = "IRQ exception",
    [SEH_EXCEPTION_SERR] = "SError exception",
    [SEH_EXCEPTION_SYNC] = "Sync exception"
};

void seh_handler(const reg_t reg_lr, const reg_t reg_esr, const seh_exception_type_t exception_type)
{
    printer_print_string("\n\n=======================================\nException occurred:\n");
    printer_print_string("\tException type:              ");
    printer_print_string(g_seh_exception_messages[exception_type]);
    printer_print_string("\n\tReturn address expected:     ");
    printer_print_address(reg_lr);

    printer_print_string("\n\tException Syndrome Register: ");
    printer_print_long_unsigned(reg_esr, PRINTER_BASE_HEXADECIMAL);

    // seh_handler_decode_esr(reg_esr);

    printer_print_string("\n\n\tGoing to infinite loop ...\n");
    while(1)
    {
        ;
    }
}
