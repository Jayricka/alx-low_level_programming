#include "main.h"

/**
 * read_textfile -we are a function that can read atext file and print it out.
 * @filename: it is the file to read from.
 * @letters: letters to be read and printed out.
 *
 * Return: number of letters to be read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)

{
	int frd;
	ssize_t length, lenwidth;
	char *ch;

	if (filename == NULL)
		return (0);
	frd = open(filename, O_RDONLY);
	if (frd == -1)
		return (0);
	ch = malloc(sizeof(char) * letters);
	if (ch == NULL)
	{
		close(frd);
		return (0);
	}
	length = read(frd, ch, letters);
	close(frd);
	if (length == -1)
	{
		free(ch);
		return (0);
	}
	lenwidth = write(STDOUT_FILENO, ch, length);
	free(ch);
	if (length != lenwidth)
		return (0);

	return (lenwidth);
}

