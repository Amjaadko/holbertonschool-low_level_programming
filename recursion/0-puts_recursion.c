#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: the string to print
 */
void _puts_recursion(char *s)
{
	if (*s == '\0') /* قاعدة التوقف: نهاية السلسلة */
	{
		_putchar('\n');
		return;
	}

	_putchar(*s); /* طباعة الحرف الحالي */
	_puts_recursion(s + 1); /* استدعاء الدالة لبقية السلسلة */
}

