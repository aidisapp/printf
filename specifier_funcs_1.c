#include "main.h"

/**
 * print_binary - Function to convert unsigned int to binary
 * @args: numbers from the variable argument list
 * Return: the converted binary representation
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	int chars = 0, found = 0, i;

	if (num == 0)
	{
		chars += write(1, "0", 1);
		return (chars);
	}

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

/**
 * print_unsigned - Function to Print unsigned decimal (%u)
 * @args: numbers from the variable arguement list
 * Return: the unsigned integer value
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int abs_val, divisor, dig_count, char_count = 0;

	abs_val = num;
	divisor = abs_val;
	dig_count = 1;

	while (divisor > 9)
	{
		divisor /= 10;
		dig_count *= 10;
	}

	while (dig_count >= 1)
	{
		char_count += _putchar(((abs_val / dig_count) % 10) + '0');
		dig_count /= 10;
	}

	return (char_count);
}

/**
 * print_octal - Function to print octal (%o)
 * @args: numbers from the variable arguement list
 * Return: the unsigned integer value
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int abs_val, divisor, dig_count, char_count = 0;

	abs_val = num;
	divisor = abs_val;
	dig_count = 1;

	while (divisor > 7)
	{
		divisor /= 8;
		dig_count *= 8;
	}

	while (dig_count >= 1)
	{
		char_count += _putchar(((abs_val / dig_count) % 8) + '0');
		dig_count /= 8;
	}

	return (char_count);
}

/**
 * print_hex_lower - Function to print hex in lowercase (%x)
 * @args: numbers from the variable arguement list
 * Return: the unsigned integer value
 */
int print_hex_lower(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int abs_val, divisor, dig_count, char_count = 0;

	abs_val = num;
	divisor = abs_val;
	dig_count = 1;

	while (divisor > 15)
	{
		divisor /= 16;
		dig_count *= 16;
	}

	while (dig_count >= 1)
	{
		char_count += _putchar(((abs_val / dig_count) % 16) +
													 ((abs_val / dig_count) % 16 < 10 ? '0' : 'a' - 10));
		dig_count /= 16;
	}

	return (char_count);
}

/**
 * print_hex_upper - Function to print hex in uppercase (%X)
 * @args: numbers from the variable arguement list
 * Return: the unsigned integer value
 */
int print_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int abs_val, divisor, dig_count, char_count = 0;

	abs_val = num;

	divisor = abs_val;
	dig_count = 1;

	while (divisor > 15)
	{
		divisor /= 16;
		dig_count *= 16;
	}

	while (dig_count >= 1)
	{
		char_count += _putchar(((abs_val / dig_count) % 16) +
		((abs_val / dig_count) % 16 < 10 ? '0' : 'A' - 10));
		dig_count /= 16;
	}

	return (char_count);
}

