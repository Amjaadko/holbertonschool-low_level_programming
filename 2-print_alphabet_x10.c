#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times,
 *                      followed by a new line, using only 2 _putchar calls
 */
void print_alphabet_x10(void)
{
    int i, j;
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 26; j++)
            _putchar(alphabet[j]);  /* طباعة الحروف (1) */

        _putchar('\n');             /* طباعة newline (2) */
    }
}

