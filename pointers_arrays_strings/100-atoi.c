#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: integer converted from string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				result = result * 10 + (s[i] - '0');
				i++;
			}
			break;
		}
		i++;
	}

	if (sign < 0)
		return (-((int)result));
	return ((int)result);
}

