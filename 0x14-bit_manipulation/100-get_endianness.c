#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Always Return: 0 or 1
 */

int get_endianness(void)
{
	unsigned int r = 1;
	char *d = (char *)&r;

	if (*d == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

