#include "main.h"
/**
 * print_string - print length of string
 * @s: character
 * @fd: first integer
 * @num: second integer
 */

void print_string(const char *s, int fd, int *num)
{
	while (*s != '\0')
	{
		write(fd, s, sizeof(char));
		s++;
		(*num)++;
	}
}
