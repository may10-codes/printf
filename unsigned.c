#include "main.h"
/**
 */
int print_undigned(unsigned int n, int(*write_func)(int fd, const void *buf, size_t n))
{
	int written = 0;

	if (n == 0)
	{
		written += write_func(1, "0", 1);
		return written;
	}
	while (n)
	{
		int digit = n % 10;
		char c = '0' + digit;
		written += write_func(1, &c, 1);
		n /= 10;
	}
	return written;
}
