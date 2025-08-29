#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times, lowercase,
 *                      followed by a new line, using only 2 _putchar calls
 */
void print_alphabet_x10(void)
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 26; j++)
            _putchar(alphabet[j]);   /* 1st _putchar: prints each letter */

        _putchar('\n');               /* 2nd _putchar: prints newline */
    }
}

