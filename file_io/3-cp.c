#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - copy content of a file to another
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
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        safe_close(fd_from), dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

    while ((rd = read(fd_from, buffer, sizeof(buffer))) > 0)
    {
        wr = write(fd_to, buffer, rd);
        if (wr == -1 || wr != rd)
            safe_close(fd_from), safe_close(fd_to),
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
    }

    if (rd == -1)
        safe_close(fd_from), safe_close(fd_to),
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);

    if (safe_close(fd_from) == -1)
        exit(100);
    if (safe_close(fd_to) == -1)
        exit(100);

    return (0);
}

