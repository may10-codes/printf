#include <stdarg.h>
#include <stdio.h>

/**
 * my_printf - custom printf function that handles the conversion specifiers u, o, x, and X
 * @format: format string
 */
void my_printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    unsigned int u;
    unsigned int o;
    unsigned int x;
    unsigned int X;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'u':
                    u = va_arg(args, unsigned int);
                    printf("%u", u);
                    break;
                case 'o':
                    o = va_arg(args, unsigned int);
                    printf("%o", o);
                    break;
                case 'x':
                    x = va_arg(args, unsigned int);
                    printf("%x", x);
                    break;
                case 'X':
                    X = va_arg(args, unsigned int);
                    printf("%X", X);
                    break;
                default:
                    printf("Invalid conversion specifier");
                    break;
            }
        }
        else
        {
            printf("%c", *format);
        }
        format++;
    }

    va_end(args);
}

