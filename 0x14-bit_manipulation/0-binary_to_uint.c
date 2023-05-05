#include "main.h"
#include <stddef.h>
/**
 * binary_to_uint - convert binary to an integer
 * @b: const char pointer to string of 0 and 1
 *
 * Return: the converted number, or 0 if there is one or more
 * chars in the string b that is not 0 or 1, or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int digit = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		digit <<= 1;
		if (*b == '1')
			digit += 1;
		b++;
	}
	return (digit);
}

