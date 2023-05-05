#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to nsigned int
 * @index: an index which i will set
 *
 * Return: "1" for success or  "-1" for error
 *
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	int ask;
	int v;

	if (index > 64)
		return (-1);

	for (v = 0; v <= 63; v++)
	{
		ask = 1 << index;
		*n &= ~ask;
	}
	return (1);
}

