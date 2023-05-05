#include "main.h"

/**
 *binary_to_uint - convert binary to an integer
 *
 *@b: const char pointer tostring of 0 and 1
 *
 *Return: 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int digit = 0;
	int j = 0;

	if (!b)
	{
		return (0);
	}
	while (b[j])
	{
		if (b[j] != '0' && (b[j] != '1'))
		{
		return (0);
		}
	digit = (digit << 1) + (b[j] - '0');
	j++;
	}
	return (digit);
}

