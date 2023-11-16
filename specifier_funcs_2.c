#include "main.h"

/**
* print_str_ASCII - this function prints a string
* with non-printable characters
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
	char hex[6] = "\\x00";

	hex[2] = ((*our_str / 16 < 10) ? '0' : 'A' - 10) + (*our_str / 16 % 16);
	hex[3] = ((*our_str % 16 < 10) ? '0' : 'A' - 10) + (*our_str % 16);
	hex[4] = '\0';
	char_count += write(1, hex, 4);
	}
	our_str++;
}

return (char_count);
}

/**
* print_pointer - Function to print pointer (%p)
* @args: values from the variable argument list
* Return: the unsigned integer value
*/
int print_pointer(va_list args)
{
void *ptr = va_arg(args, void *);
unsigned long int address, remainder;
int count = 0, i;
char hex[16];

if (ptr == NULL)
{
	_putchar('(');
	_putchar('n');
	_putchar('i');
	_putchar('l');
	_putchar(')');
	return (5);
}
address = (unsigned long int)ptr;

_putchar('0');
_putchar('x');

if (address == 0)
{
	_putchar('0');
	count++;
}

while (address != 0)
{
	remainder = address % 16;
	if (remainder < 10)
	hex[count] = remainder + '0';
	else
	hex[count] = remainder - 10 + 'a';

i	address /= 16;
	count++;
}
for (i = count - 1; i >= 0; i--)
_putchar(hex[i]);
return (count + 2);
}

/**
 * print_integer_positive - this function is made to handle
 *
 * the positive integer cases
 *
 * @args: these are arguments from the argument list (variable)
 *
 * Return: the positive integer value
 */

int print_integer_positive(va_list args)
{
	int pos_int;

	pos_int = 0;
	int *int_ptr = va_arg(args, int *);

	if (int_ptr == NULL)
	{
		return (write(1, "(null)", 6));
	}

	if (*int_ptr >= 0)
	{
		pos_int += _putchar('+');
		pos_int += prnt_dec_int(*int_ptr);
	}
	else
	{
		pos_int += prnt_dec_int(*int_ptr);
	}

	return (pos_int);
}


/**
 * print_space_str - this function is made to handle
 *
 * the space or string padding
 *
 * @args: these are the arguments from the argument list (variable)
 *
 * Return: the positive integer value
 */

int print_space_str(va_list args)
{
	int space, str_space, spacing;

	str_space = 0;

	space = 0;

	int spc_width = va_arg(args, int);
	char *strng = va_arg(args, char *);

	if (str == NULL)
	{
		space += write(1, "(null)", 6);
		return (space);
	}

	while (str[str_space] != '\0')
	{
		str_space++;
	}
	spacing = (str_space < space) ? (space - str_space) : 0;

	while (spacing > 0)
	{
		space += write(1, " ", 1);
		spacing--;
	}

	return (space);
}

/**
 * print_hash_specifier - this function is made to handle
 *
 * the printing of the hash flags
 *
 * @args: these are the arguments from the argument list (variable)
 *
 * Return: this will be the "#" flag
 */

int print_hash_specifier(va_list args)
{
	int hash;

	hash = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		hash += write(1, "(null)", 6);
		return (hash);
	}

	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			hash += write(1, &(*str - ('a' - 'A')), 1);
		}
		else
		{
			hash += write(1, str, 1);
		}
		str++;
	}

	return (hash);
}
