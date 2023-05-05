#include "main.h"
#include <stdio.h>

/**
 * flip_bits - shows number of bits required to flip from a number
 * @n: unsigned long int
 * @m: the bit which will be flipped
 *
 * Return: count
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dumb = n ^ m;
	unsigned int tell = 0;

	while (dumb != 0)
	{
		if (dumb & 1)
		{
			tell++;
		}
		dumb = dumb >> 1;
	}
	return (tell);
}
