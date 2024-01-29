#include "main.h"

/**
 * _printf - custom printf
 * @format: printf format
 * Return: 0
 */
size_t _strlen
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
				write (fd, &c, sizeof(char));
				num++;
			}
			else if (*format == 's')
			{
				s = va_arg(alx, char *);
				while (*s != '\0')
				{
					write (fd, s, sizeof(char));
					s++;
					num++;
				}
			}
			else if (*format == '%')
			{
				write (fd, "%", sizeof(char));
				num++;
			}
		}
		else
		{
			write(1, format, sizeof(char));
			num++;
		}
		format++;
	}
	va_end(alx);
	return (num);
}
