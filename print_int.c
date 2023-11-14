#include "main.h"
#include <stdarg.h>

/**
 * print_number - this function prints integer numbers
 * @b: this is the integer to be printed
 *
 * Return: will have to be the number of characters printed
 */

int print_number(int b)
{
	char prn[20];
	int chars;
	int a;

	a = 0;

	chars = 0;

	if (b == 0)
	{
		chars += _putchar('0');
		return (chars);
	}

	if (b < 0)
	{
		chars += _putchar('-');
		b = -b;
	}

	while (b != 0)
	{
		prn[a++] = b % 10 + '0';
		b /= 10;
	}

	while (--a >= 0)
	{
		chars += _putchar(prn[a]);
	}

	return (chars);
}
