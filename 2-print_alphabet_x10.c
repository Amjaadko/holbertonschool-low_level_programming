#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times in lowercase
 * Return: void
 */
void print_alphabet_x10(void)
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 'a'; j <= 'z'; j++)
        {
            _putchar(j);
        }
        _putchar('\n');
    }
}

/* Optional main for testing only; remove before submission
int main(void)
{
    print_alphabet_x10();
    return (0);
}
*/

