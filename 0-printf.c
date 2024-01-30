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
	int d;

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
				if (s == NULL)
				{
					write(fd, "(nil)", 5);
				}
				print_string(s, fd, &num);
			}
			else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(alx, int);
				handle_d_i(1, d);
				num++;
			}
			else if (*format == '%')
			{
				c = va_arg(alx, int);
				write(fd, "%", sizeof(char));
				num++;
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
