#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *s)
{
	int i = 0;

	/* iterate through the string */
	while (s[i] != '\0')
	{
		/* capitalize the first character of the string */
		if (i == 0 && s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;

		/* capitalize after word separators */
		if ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		     s[i] == ',' || s[i] == ';' || s[i] == '.' ||
		     s[i] == '!' || s[i] == '?' || s[i] == '"' ||
		     s[i] == '(' || s[i] == ')' || s[i] == '{' ||
		     s[i] == '}') && s[i + 1] >= 'a' && s[i + 1] <= 'z')
		{
			s[i + 1] = s[i + 1] - 32;
		}
		i++;
	}
	return (s);
}

