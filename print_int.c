#include "main.h"
#include <stdarg.h>

/**
 * print_number - Print integer numbers
 * @b: Integer to be printed
 *
 * Return: Number of characters printed
 */

int print_number(int b)
{
	char prn[20];
	int chars;
	int a;

	chars = 0;


	if (b < 0)
	{
		chars += _putchar('-');
		b = -b;
	}

	if (b == 0)
		chars += _putchar('0');


	a = 0;
	while (b != 0)
	{
		prn[a++] = b % 10 + '0';
		b /= 10;
	}

	while (--a >= 0)
		chars += _putchar(prn[a]);

	return (chars);
}
