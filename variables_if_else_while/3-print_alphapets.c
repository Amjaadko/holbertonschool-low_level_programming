#include <stdio.h>

/**
 * main - prints the alphabet in lowercase and then uppercase
 *
 * Return: 0
 */
int main(void)
{
    char c;

    /* lowercase */
    for (c = 'a'; c <= 'z'; c++)
        putchar(c);

    /* uppercase */
    for (c = 'A'; c <= 'Z'; c++)
        putchar(c);

    putchar('\n');

    return (0);
}
