#include "main.h"
#include <stdio.h>

/**
 * get_bit - printing value of a bit at a given index
 * @n: unsigned long int
 *
 * @index: bit
 * Return: index or -1 on error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bite;

	if (index >= 64)

	return (-1);
	bite = (n >> index) & 1;

	return (bite);
}
