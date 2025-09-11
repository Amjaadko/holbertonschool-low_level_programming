#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number to calculate factorial for
 *
 * Return: factorial of n, -1 if n < 0
 */
int factorial(int n)
{
	if (n < 0)
		return (-1); /* error case */
	if (n == 0)
		return (1); /* factorial of 0 is 1 */
	return (n * factorial(n - 1)); /* recursive call */
}

