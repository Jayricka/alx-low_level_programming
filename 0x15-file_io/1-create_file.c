#include "main.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file -a function that creates a file.
 * @filename: created name of the file.
 * @text_content: NULL terminated string.
 *
 * Return: 1 or -1.
 *
 */

int create_file(const char *filename, char *text_content)
{
	int frd;

	if (filename == NULL)
		return (-1);

	frd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (frd == -1)
		return (-1);

	if (text_content != NULL)
	{
		write(frd, text_content, strlen(text_content));
	}
	close(frd);

	return (1);
}

