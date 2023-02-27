#include "main.h"
/**
 * _strlen - returns the length of a string
 * @b: string
 * Return: length
 */
int _strlen(char *b)
{
	int length = 0;

	while (*b != '\0')
	{
		length++;
		b++;
	}

	return (length);
}
