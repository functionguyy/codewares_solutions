#include "main.h"
/**
 * recursive_sum - recursively adds the digits in a number
 * @num: number
 * @exponent: exponent of number
 *
 * Return: returns the sum of all the digits in a number
 */
int recursive_sum(int num, int exponent)
{
	/* declar variables */
	int number;

	number = 0;

	if (exponent == 0)
		return (0);
	number = num / exponent;
	num = num - (number * exponent);
	exponent /= 10;

	return (number + recursive_sum(num, exponent));
}
/**
 * digital_root - computes the digital root of a natural number
 * @n: natural number
 *
 * Return: returns the digital root or n otherwise
 */
int digital_root(int n)
{
	/* declare variables */
	int digit, count, exponent;

	/* initialize variables */
	digit = n;
	count = 0;
	exponent = 1;

	if (n == 0)
		return (0);

	while (n > 9)
	{
		/* calculate exponent */
		while (digit > 0)
		{
			digit = digit / 10;
			count++;
		}
		while (count > 1)
		{
			exponent = exponent * 10;
			count--;
		}
		n = recursive_sum(n, exponent);
	}

	return (n);
}
