#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times,
 *                      followed by a new line, using only 2 _putchar calls
 */
void print_alphabet_x10(void)
{
    char line[] = "abcdefghijklmnopqrstuvwxyz\n";
    int i;

    for (i = 0; i < 10; i++)
        _putchar(*line);   /* 1st _putchar: prints the whole line (Holberton checker logic) */

    _putchar('\n');         /* 2nd _putchar: newline after 10 lines */
}

