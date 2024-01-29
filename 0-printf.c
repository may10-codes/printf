#include "main.h"

/**
 * _printf - custom printf
 * @format: printf format
 * Return: 0
 */

void print_binary(unsigned int n, int fd)
{
	char digit;

	if (n > 1)
	{
		print_binary(n / 2, fd);
	}
	digit = (n % 2) + '0';
	write(fd, &digit, sizeof(char));
}
int _printf(const char *format, ...)
{
	unsigned int binary_arg;
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
			else if (*format == 'b')
			{
				binary_arg = va_arg(alx, unsigned int);
				print_binary(binary_arg, 1);
				num++;
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

/**
 * print_number - prints an integer
 * @n: integer to print
 * @fd: file descriptor
 */
void print_number(int n, int fd)
{
	if (n / 10)
		print_number(n / 10, fd);
	write(fd, &"0123456789"[n % 10], sizeof(char));
}

/**
 * count_digits - counts the number of digits in an integer
 * @n: integer to count digits of
 * Return: number of digits
 */
int count_digits(int n)
{
	int count = 0;

	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}
