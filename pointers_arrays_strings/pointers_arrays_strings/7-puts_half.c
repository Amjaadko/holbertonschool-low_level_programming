#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: string to print
 */
void puts_half(char *str)
{
	int len = 0;
	int i;

	if (!str)
		return;

	/* حساب طول السلسلة */
	while (str[len] != '\0')
		len++;

	/* تحديد البداية حسب طول السلسلة */
	if (len % 2 == 0)
		i = len / 2;
	else
		i = (len + 1) / 2;

	/* طباعة النصف الثاني */
	for (; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

