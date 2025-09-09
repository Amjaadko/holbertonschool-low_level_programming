#include "main.h"

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: number to check
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	return (_is_prime(n, n - 1));
}

/**
 * _is_prime - helper recursive function to check divisibility
 * @n: number to check
 * @i: current divisor
 * Return: 1 if prime, 0 otherwise
 */
int _is_prime(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0)
		return (0);
	return (_is_prime(n, i - 1));
}

