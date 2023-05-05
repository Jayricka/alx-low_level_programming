#include "main.h"

/**
 * print_binary - prints binary
 * @n: number
 *
 * Return: binary
 */
void print_binary(unsigned long int n)
{
	int pen;
	unsigned long int puff, mark = 1;

	for (pen = 0, puff = n; puff > 0; pen++)
		puff >>= 1;

	if (--pen > 0)
		mark <<= pen;

	for (; mark > 0; mark >>= 1)
	{
		if (n & mark)
			_putchar('1');
		else
			_putchar('0');
	}
}

