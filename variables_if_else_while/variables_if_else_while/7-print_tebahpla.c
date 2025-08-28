#include <stdio.h>

int main(void)
{
    int ch;

    for (ch = 'z'; ch >= 'a'; ch--)
    {
        putchar(ch);
    }
    putchar('\n');
    return (0);
}
