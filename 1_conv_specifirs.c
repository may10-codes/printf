#include <stdarg.h>
#include <stdio.h>

/**
 * my_printf - custom printf function that handles the conversion specifiers d and i
 * @format: format string
 */
void my_printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    int i;
    char c;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'd':
                case 'i':
                    i = va_arg(args, int);
                    printf("%d", i);
                    break;
                case 'c':
                    c = (char)va_arg(args, int);
                    printf("%c", c);
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

