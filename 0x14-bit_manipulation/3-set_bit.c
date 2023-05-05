#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to nsigned int
 * @index: an index which i will set
 *
 * Return: "1" for success or  "-1" for error
 *
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	int me;
		if (index > 64)
			return (-1);

		me = 1 << index;
		*n |= me;

		return (1);
}
