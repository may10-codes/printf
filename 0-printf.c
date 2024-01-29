#include "main.h"

/**
 * print_binary - Prints a binary number.
 * @n: Binary number to print.
 * @fd: File descriptor.
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
 * @format: Printf format.
 * Return: Number of characters printed.
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
				while (*s != '\0')
				{
					write(fd, s, sizeof(char));
					s++;
					num++;
				}
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

/**
 * print_number - Prints an integer.
 * @n: Integer to print.
 * @fd: File descriptor.
 */
void print_number(int n, int fd)
{
	if (n / 10)
		print_number(n / 10, fd);
	write(fd, &"0123456789"[n % 10], sizeof(char));
}

/**
 * count_digits - Counts the number of digits in an integer.
 * @n: Integer to count digits of.
 * Return: Number of digits.
 */
int count_digits(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return count;
}

