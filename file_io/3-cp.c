#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_exit - Print error message and exit with code
 * @code: exit code
 * @message: error message
 * @file: file name
 */
void error_exit(int code, const char *message, const char *file)
{
    dprintf(STDERR_FILENO, message, file);
    exit(code);
}

/**
 * main - program that copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t rd, wr;
    char buffer[1024];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from %s\n", argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        close(fd_from);
        error_exit(99, "Error: Can't write to %s\n", argv[2]);
    }

    while ((rd = read(fd_from, buffer, 1024)) > 0)
    {
        wr = write(fd_to, buffer, rd);
        if (wr == -1 || wr != rd)
        {
            close(fd_from);
            close(fd_to);
            error_exit(99, "Error: Can't write to %s\n", argv[2]);
        }
    }

    if (rd == -1) /* read error */
    {
        close(fd_from);
        close(fd_to);
        error_exit(98, "Error: Can't read from %s\n", argv[1]);
    }

    if (close(fd_from) == -1)
        error_exit(100, "Error: Can't close fd %d\n", argv[1]);

    if (close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd %d\n", argv[2]);

    return (0);
}

