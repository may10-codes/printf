#include "main.h"
/**
 * print_binary - print binary specifier
 * @n: first integer
 * @fd: second integer
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
