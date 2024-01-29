#include "main.h"
/**
 * print_binary - Prints a binary representation of an unsigned int.
 * @n: Unsigned int to be converted to binary.
 * @fd: File descriptor to write to (stdout in this case).
 */
int _printf(const char *format, ...)
{
	unsigned int binary_arg;
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
			else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(alx, int);
				handle_d_i(1, d);
				num++;
			}
			else if (*format == 's')
			{
				s = va_arg(alx, char *);
				print_string(s, fd, &num);
			}
			else if (*format == 'b')
			{
				binary_arg = va_arg(alx, unsigned int);
				print_binary(binary_arg, fd);
			}
			else if (*format == '%')
			{
				num += write(fd, "%", sizeof(char));
			}
		}
		else
		{
			num += write(fd, format, sizeof(char));
		}
		format++;
	}
	va_end(alx);
	return num;
}
