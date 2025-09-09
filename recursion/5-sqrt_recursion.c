#include "main.h"

/**
 * _sqrt_helper - recursive helper to find sqrt
 * @n: number
 * @i: iterator
 * Return: natural square root or -1
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns natural square root of a number
 * @n: number to calculate
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}

