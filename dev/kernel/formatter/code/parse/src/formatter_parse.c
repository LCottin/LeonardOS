#include "formatter_krn.h"
#include "strings_utils_usr.h"

void formatter_parse(stream_t *stream, const char_t *format, va_list args)
{
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch(*format)
            {
                /* Print char */
                case 'c':
                {
                    const char_t c = (char_t)va_arg(args, int32_t);
                    stream->write_byte(c, stream);
                    break;
                }

                /* Print string */
                case 's':
                {
                    const char *str = va_arg(args, const char *);

                    while (*str)
                    {
                        stream->write_byte(*str++, stream);
                    }
                    break;
                }

                /* Print signed integer */
                case 'd':
                {
                    char_t buffer[32];
                    const int64_t i = (int64_t)va_arg(args, int64_t);
                    char_t *str     = strings_utils_itoa(STRINGS_UTILS_BASE_DECIMAL, i, buffer);

                    while (*str)
                    {
                        stream->write_byte(*str++, stream);
                    }
                    break;
                }

                /* Print unsigned integer */
                case 'u':
                {
                    char_t buffer[32];
                    const uint64_t i = (uint64_t)va_arg(args, uint64_t);
                    char_t *str      = strings_utils_utoa(STRINGS_UTILS_BASE_DECIMAL, i, buffer);

                    while (*str)
                    {
                        stream->write_byte(*str++, stream);
                    }
                    break;
                }

                /* Print hexadecimal */
                case 'x':
                case 'X':
                {
                    char_t buffer[32];
                    const uint64_t i = (uint64_t)va_arg(args, uint64_t);
                    char_t *str      = strings_utils_utoa(STRINGS_UTILS_BASE_HEXADECIMAL, i, buffer);

                    while (*str)
                    {
                        stream->write_byte(*str++, stream);
                    }
                    break;
                }

                default:
                {
                    stream->write_byte('%', stream);
                    stream->write_byte(*format, stream);
                    break;
                }
            }
        }
        else
        {
            stream->write_byte(*format, stream);
        }

        format++;
    }
}
