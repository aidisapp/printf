#include "main.h"

/**
 * print_binary - Function to convert unsigned int to binary
 * @args: numbers from the variable arguement list
 * Return: the converted binary representation
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int chars = 0, found = 0, i;

	for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
	{
		if ((num >> i) & 1)
		{
			found = 1;
			chars += write(1, "1", 1);
		}
		else if (found)
			chars += write(1, "0", 1);

		if (found && (num >> i) == 0)
			break;
	}

	return (chars);
}
