#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times in lowercase
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	int i;
	char ch;

	for (i = 0; i < 10; i++)
	{
		for (ch = 'a'; ch <= 'z'; ch++)
<<<<<<< HEAD
			_putchar(ch);
		_putchar('\n');
	}
}
=======
		{
			_putchar(ch);
		}
		_putchar('\n');
	}
}

>>>>>>> df4f1da (Add 2-print_alphabet_x10 with Betty style fixed)
