#include "main.h"
/**
 * main - program that encodes a string
 *
 * Return: returns 0 always
 */
int main(void)
{
	char *str = "Success";
	char *newStr;


	newStr = DuplicateEncoder(str);

	printf("Encode string is %s\n", newStr);

	return (0);
}
