#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int safe_close(int fd);

/**
 * main - Main function to copy files
 * @argc: The number of passed arguments
 * @argv: The pointers to array arguments
 * Return: 0 on success, exits on failure
 */
int main(int argc, char *argv[])
{
    char buffer[1024];
    int from_fd, to_fd;
    ssize_t rd, wr;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    from_fd = open(argv[1], O_RDONLY);
    if (from_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (to_fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        safe_close(from_fd);
        exit(99);
    }

    while ((rd = read(from_fd, buffer, 1024)) > 0)
    {
        wr = write(to_fd, buffer, rd);
        if (wr == -1 || wr != rd)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            safe_close(from_fd);
            safe_close(to_fd);
            exit(99);
        }
    }

    if (rd == -1) /* read error */
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        safe_close(from_fd);
        safe_close(to_fd);
        exit(98);
    }

    if (safe_close(to_fd) == -1)
        exit(100);
    if (safe_close(from_fd) == -1)
        exit(100);

    return (0);
}

/**
 * safe_close - safely closes a file descriptor
 * @fd: file descriptor
 * Return: 0 on success, -1 on failure
 */
int safe_close(int fd)
{
    int error = close(fd);

    if (error == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
    return (error);
}

