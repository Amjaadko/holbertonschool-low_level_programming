#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int i = 0, j;
	char temp;

	/* احصلي طول السلسلة */
	while (s[i] != '\0')
		i++;

	j = i - 1; /* آخر حرف */

	/* تبادل الحروف من البداية للنهاية */
	for (i = 0; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

