#include "main.h"
/**
 * main - program tests the function that computes the digital root of natural
 * numbers
 *
 * Return: returns 0 on successful execution
 */
int main(void)
{
	int n, digit_root;

	/* change n to any natural number */
	n = 493139;

	digit_root = digital_root(n);

	printf("Digital root of %d = %d\n", n, digit_root);

	return (0);
}
