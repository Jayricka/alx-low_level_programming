#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * main - accepts arguements.
 * @argc: number of arguements it accepted by main function
 * @argv: arguement vector.
 *
 * Return: 0.
 */

void print_error_and_exit(int exit_code, const char *message, const char *file_name, int fd) 
{
    dprintf(STDERR_FILENO, message, file_name);
    if (fd != -1) {
        close(fd);
    }
    exit(exit_code);
}

int main(int argc, char *argv[]) 
{
    int fd_from, fd_to;
    ssize_t read_size;
    ssize_t write_size;
    char buffer[BUFFER_SIZE];

    if (argc != 3) 
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) 
    {
        print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1], -1);
    }

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) 
    {
        print_error_and_exit(99, "Error: Can't write to %s\n", argv[2], fd_from);
    }

    while ((read_size = read(fd_from, buffer, BUFFER_SIZE)) > 0) 
    {
        write_size = write(fd_to, buffer, read_size);
        if (write_size != read_size) 
        {
            print_error_and_exit(99, "Error: Can't write to %s\n", argv[2], fd_from);
        }
    }

    if (read_size == -1) 
    {
        print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1], fd_from);
    }

    if (close(fd_from) == -1) 
    {
        print_error_and_exit(100, "Error: Can't close fd %d\n", argv[1], fd_from);
    }

    if (close(fd_to) == -1) 
    {
        print_error_and_exit(100, "Error: Can't close fd %d\n", argv[2], fd_to);
    }

    return 0;
}

