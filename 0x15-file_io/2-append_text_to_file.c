#include "main.h"

/**
 * append_text_to_file -  appends text at the end of a file.
 * @filename: name of file to append
 * @text_content: text added to the file
 *
 * Return: (1) on success
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int frd;

	if (filename == NULL)
		return (-1);

	frd = open(filename, O_WRONLY | O_APPEND);

	if (frd == -1)
		return (-1);

	if  (text_content != NULL)
	{
		write(frd, text_content, strlen(text_content));
	}
	close(frd);

	return (1);
}

