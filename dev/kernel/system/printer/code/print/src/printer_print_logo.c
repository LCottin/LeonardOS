#include "printer_krn.h"

void printer_print_logo(void)
{
    printer_print_string("\n\
           __                                _   ___  __\r\n\
          / /  ___  ___  _ __   __ _ _ __ __| | /___\\/ _\\\r\n\
         / /  / _ \\/ _ \\|  _ \\ / _  |  __/ _  |//  //\\ \\\r\n\
        / /__|  __/ (_) | | | | (_| | | | (_| / \\_// _\\ \\\r\n\
        \\____/\\___|\\___/|_| |_|\\____|_|  \\____\\___/  \\__/\r\n\n\
                             LeonardOS\r\n\
                    ---------------------------\r\n\
                    Bare Metal Operating System\r\n\n");
}
