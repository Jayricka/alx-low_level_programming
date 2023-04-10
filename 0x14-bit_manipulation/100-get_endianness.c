#include "main.h"

/**
 * get_endianness - Checks the endianness in the function
 *
 * Return: 0 if big endian and -1 if little endian
 */


int get_endianness(void)
{
	int n = 1;
	char *coin = (char *) (&n);

	if (*coin == 1)
		return (1);

	return (0);
}
