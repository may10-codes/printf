#include "main.h"
/**
 * _printf - creating a custom printf
 * @format: string format
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list alx;
	char c;
	char *s;
	int fd = 1;
	int num = 0;

	va_start(alx, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c =  va_arg(alx, int);
				num += write(fd, &c, sizeof(char));
			}
			else if (*format == 's')
			{
				s = va_arg(alx, char *);
				print_string(s, fd, &num);
			}
		}
		else
		{
			num += write(fd, format, sizeof(char));
		}
		format++;
	}
	va_end(alx);
	return (num);
}
