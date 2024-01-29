#include "main.h"
/**
 * handle_d_i - d and i specifier
 * @fd: integer
 * @alx: variadic function
 */

void handle_d_i(int fd, va_list alx)
{
	int num;
	char num_char;

	num = va_arg(alx, int);
	num_char = num + '0';
	write(fd, &num_char, sizeof(int));
}
