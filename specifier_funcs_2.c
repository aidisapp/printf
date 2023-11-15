#include "main.h"

/**
 * print_str_ASCII - this function prints a string
 *
 * with non-printable characters
 *
 * @args: these are arguments from the variable argument list
 *
 * Return: this will be the number of characters printed
 */

int print_str_ASCII(va_list args)
{
	const char *our_str = va_arg(args, const char *);
	int char_count = 0;

	if (our_str == NULL)
	{
		char_count += write(1, "(null)", 6);
		return (char_count);
	}

	while (*our_str)
	{
		if (*our_str >= 32 && *our_str < 127)
		{
			char_count += write(1, our_str, 1);
		}
		else
		{
			char hex[5] = "\\x00";

			hex[2] = ((*our_str / 16 < 10) ? '0' : 'A' - 10);
			hex[3] = ((*our_str % 16 < 10) ? '0' : 'A' - 10);
			char_count += write(1, hex, 4);
		}
		our_str++;
	}

	return (char_count);
}
