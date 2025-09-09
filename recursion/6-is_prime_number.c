#include "main.h"

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: the number to check
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (check_prime(n, n - 1));
}

/**
 * check_prime - helper function to check prime recursively
 * @n: the number to check
 * @i: current divisor
 * Return: 1 if prime, 0 otherwise
 */
int check_prime(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0)
		return (0);
	return (check_prime(n, i - 1));
}

