#include "main.h"
/**
 * handle_d_i - d and i specifier
 * @fd: integer
 * @alx: variadic function
 */

void handle_d_i(int fd, int nume)
{
	int i = 0;
	char str[12];

	if (nume < 0)
	{
		write(fd, "-", 1);
		nume = -nume;
	}
	do
	{
		str[i++] = nume % 10 + '0';
		nume /= 10;
	} while (nume != 0);

	while (i > 0)
	{
		write(fd, &str[--i], 1);
	}

}
