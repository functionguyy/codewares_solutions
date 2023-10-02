#include "main.h"
/**
 * main - program that encodes a string
 *
 * Return: returns 0 always
 */
int main(void)
{
	char *str = "ijN8Q0}P7PR60<//N65SSZRTOPa2=((0?+Qlk%1S7T{PlU&a=>S>Sl^i1^)cZ{(}/50fT(==e} `Q4``W(MQYa)`))}}))";
	char *newStr;


	newStr = DuplicateEncoder(str);

	printf("Encode string is %s\n", newStr);

	free(newStr);

	return (0);
}
