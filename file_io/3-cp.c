#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int safe_close(int fd);
void err_exit_str(int code, const char *fmt, const char *arg);
void err_exit_fd(int code, const char *fmt, int fd);

/**
 * safe_close - close fd and print error on failure
 * @fd: file descriptor
 * Return: 0 on success, -1 on failure
 */
int safe_close(int fd)
{
    int rc = close(fd);

    if (rc == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
    return (rc);
}

/**
 * err_exit_str - print formatted message with string argument and exit
 * @code: exit code
 * @fmt: printf format (expects %s)
 * @arg: string argument
 */
void err_exit_str(int code, const char *fmt, const char *arg)
{
    dprintf(STDERR_FILENO, fmt, arg);
    exit(code);
}

/**
 * err_exit_fd - print formatted message with int argument and exit
 * @code: exit code
 * @fmt: printf format (expects %d)
 * @fd: int argument (fd)
 */
void err_exit_fd(int code, const char *fmt, int fd)
{
    dprintf(STDERR_FILENO, fmt, fd);
    exit(code);
}

/**
 * main - copy content of a file to another
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success (exits with codes on failure)
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
        err_exit_str(98, "Error: Can't read from file %s\n", argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        safe_close(fd_from);
        err_exit_str(99, "Error: Can't write to %s\n", argv[2]);
    }

    while ((rd = read(fd_from, buffer, sizeof(buffer))) > 0)
    {
        wr = write(fd_to, buffer, rd);
        if (wr == -1 || wr != rd)
        {
            safe_close(fd_from);
            safe_close(fd_to);
            err_exit_str(99, "Error: Can't write to %s\n", argv[2]);
        }
    }

    /* If read() returned -1 at any point -> read error (98) */
    if (rd == -1)
    {
        safe_close(fd_from);
        safe_close(fd_to);
        err_exit_str(98, "Error: Can't read from file %s\n", argv[1]);
    }

    if (safe_close(fd_from) == -1)
        err_exit_fd(100, "Error: Can't close fd %d\n", fd_from);
    if (safe_close(fd_to) == -1)
        err_exit_fd(100, "Error: Can't close fd %d\n", fd_to);

    return (0);
}

