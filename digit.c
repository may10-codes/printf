#include "main.h"
/**
 * handle_d_i - d and i specifier
 * @fd: integer
 * @nume: variadic function
 */

void handle_d_i(int fd, int nume)
{
	int i = 0;
	int count;
	char *str;

	if (nume ==  0)
	{
		count = 1;
	}

	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
	{
		return;
	}
	if (nume < 0)
	{
		str[0] = '-';
		nume = -nume;
		i = 1;
	}
	do {
		str[i++] = nume % 10 + '0';
		nume /= 10;
	} while (nume != 0);

	str[i] = '\0';

	while (i > 0)
	{
		write(fd, &str[--i], 1);
	}

	free(str);

}
