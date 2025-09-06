#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @s: string to print
 */
void print_rev(char *s)
{
	int i = 0;

	/* احصلي طول السلسلة */
	while (s[i] != '\0')
		i++;

	/* اطبعي الحروف من الأخير للأول */
	while (i > 0)
	{
		i--;
		_putchar(s[i]);
	}
	_putchar('\n');
}

