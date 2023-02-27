#include "main.h"
/**
 * print_rev - imprime en reversa
 * @k: string
 * return: 0
 */
void print_rev(char *k)
{
	int string = 0;
	int o;

	while (*k != '\0')
	{
		length++;
		k++;
	}
	k--;
	for (o = lenght; o > 0; o--)
	{
		_putchar(*k);
		k--;
	}

	_putchar('\n');
}
