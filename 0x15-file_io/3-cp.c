#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024
/**
 * main - accepts arguements.
 * @argc: number of arguements accepted.
 * @argv: arguement vector.
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int old, car;
	ssize_t character;
	char buffer[BUFFER_SIZE];
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	old = open(argv[1], O_RDONLY);
	car  = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, permissions);
	if (old == -1 || car == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open or create file(s).\n");
		exit(98);
	}
	while ((character = read(old, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(car, buffer, character) != character)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (character == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(old) == -1 || close(car) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", errno);
		exit(100);
	}
	return (0);
}


