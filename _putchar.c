#include <unistd.h>
#include "main.h"

<<<<<<< HEAD
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
    return write(1, &c, 1);
=======
int _putchar(char c)
{
    return (write(1, &c, 1));
>>>>>>> df4f1da (Add 2-print_alphabet_x10 with Betty style fixed)
}
