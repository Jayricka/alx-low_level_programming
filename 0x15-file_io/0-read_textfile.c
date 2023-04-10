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
	int fd;
	ssize_t lask, skippy;
	char *ch;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ch = malloc(sizeof(char) * letters);
	if (ch == NULL)
	{
		close(fd);
		return (0);
	}
	lask = read(fd, ch, letters);
	close(fd);
	if (lask == -1)
	{
		free(ch);
		return (0);
	}
	skippy = write(STDOUT_FILENO, ch, lask);
	free(ch);
	if (lask != skippy)
		return (0);

	return (skippy);
}
