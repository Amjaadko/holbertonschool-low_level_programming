#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_exit - Print error message and exit with code
 * @code: exit code
 * @message: error message format string
 * @arg: argument for message
 */
void error_exit(int code, const char *message, int arg)
{
    dprintf(STDERR_FILENO, message, arg);
    exit(code);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, cl_from, cl_to;
    ssize_t rd, wr;
    char buffer[1024];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

    while ((rd = read(fd_from, buffer, 1024)) > 0)
    {
        wr = write(fd_to, buffer, rd);
        if (wr == -1 || wr != rd)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    if (rd == -1) /* read error */
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    cl_from = close(fd_from);
    if (cl_from == -1)
        error_exit(100, "Error: Can't close fd %d\n", fd_from);

    cl_to = close(fd_to);
    if (cl_to == -1)
        error_exit(100, "Error: Can't close fd %d\n", fd_to);

    return (0);
}

