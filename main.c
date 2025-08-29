#include <unistd.h>

/* _putchar function */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* main function */
int main(void)
{
    int i, j;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    for (i = 0; i < 10; i++)
    {
        j = 0;
        while (letters[j])
            _putchar(letters[j++]);
        _putchar('\n'); /* ثاني _putchar */
    }
    return 0;
}
