#include <stdarg.h>
#include <stdio.h>

/**
 * my_printf - custom printf function that handles the conversion specifiers d, i, and c
 * @format: format string
 * @...: variable arguments
 */
void my_printf(const char *format, ...)
{
    /* Move variable declarations to the beginning of the block */
    va_list args;
    int i;
    char c;

    va_start(args, format);

    /* Iterate through the format string */
    while (*format)
    {
        if (*format == '%')
        {
            format++;

            /* Check the conversion specifier after '%' */
            switch (*format)
            {
                case 'd':
                case 'i':
                    /* Handle integer */
                    i = va_arg(args, int);
                    printf("%d", i);
                    break;
                case 'c':
                    /* Handle character */
                    c = (char)va_arg(args, int);
                    printf("%c", c);
                    break;
                default:
                    /* Invalid conversion specifier */
                    printf("Invalid conversion specifier");
                    break;
            }
        }
        else
        {
            /* Print non-'%' characters as they are */
            printf("%c", *format);
        }

        /* Move to the next character in the format string */
        format++;
    }

    va_end(args);
}

