#include "main.h"

/**
 * print_binary - Prints a binary representation of an unsigned int.
 * @n: Unsigned int to be converted to binary.
 * @fd: File descriptor to write to (stdout in this case).
 */
void print_binary(unsigned int n, int fd)
{
	char digit;

	if (n > 1)
		print_binary(n / 2, fd);

	digit = (n % 2) + '0';
	write(fd, &digit, sizeof(char));
}

/**
 * _printf - Custom printf function.
 * @format: Format string with conversion specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	unsigned int binary_arg;
	va_list args;
	char c;
	char *s;
	int fd = 1; /* Default file descriptor is STDOUT */
	int num = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(fd, &c, sizeof(char));
				num++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s != '\0') { write(fd, s++, sizeof(char)); num++; }
			}
			else if (*format == 'b')
			{
				binary_arg = va_arg(args, unsigned int);
				print_binary(binary_arg, fd);
				num++;
			}
			else if (*format == '%')
			{
				write(fd, "%", sizeof(char));
				num++;
			}
		}
		else
		{
			write(fd, format, sizeof(char));
			num++;
		}
		format++;
	}
	va_end(args);
	return num;
}

