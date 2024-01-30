#include "main.h"
/**
 * _printf - creating a custom printf
 * @format: string format
 * Return: 0
 */
int _printf(const char *format, ...)
{
/*	unsigned int binary_arg;*/
	va_list alx;
	char c;
	char *s;
	int fd = 1;
	int num = 0;
/*	int d;*/

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
			/*else if (*format == 'd' || *format == 'i')
			{
				d = va_arg(alx, int);
				handle_d_i(1, d);
				num++;
				}*/
			else if (*format == 's')
			{
				s = va_arg(alx, char *);
				print_string(s, fd, &num);
			}
			/*else if (*format == 'b')
			{
				binary_arg = va_arg(alx, unsigned int);
				print_binary(binary_arg, fd);
				}*/
			/*	else if (*format == 'u')
			{
				print_unsigned(va_arg(alx,unsigned int, write));
				num++;
				}*/
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
	return (num);
}
