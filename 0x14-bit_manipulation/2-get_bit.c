#include "main.h"
#include <stdio.h>

/**
 * get_bit - printing value of a bit at a given index
 * @n: unsigned long int
 *
 * @index: bet
 * Return: index or -1 on error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bet;

	if (index >= 64)

	return (-1);
	bet = (n >> index) & 1;

	return (bet);
}
