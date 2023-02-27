#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @dstv: string to print
 */
void _puts(char *dstv)
{
	while (*dstv != '\0')
	{
		_putchar(*dstv++);
	}
		_putchar('\n');
}
