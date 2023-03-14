#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly alloacted space with a copy of arg
 * @str: the string to copy
 *
 * Return: pointer to array or null
 */

char *_strdup(char *str)
{
	char *strNew;
	int i;
	int j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i++;
	strNew = malloc(sizeof(*str) * i);
	if (strNew == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\0')
	{
		strNew[j] = str[j];
		j++;
	}
	return (strNew);
}
