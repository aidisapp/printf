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

	address /= 16;
	count++;
}
for (i = count - 1; i >= 0; i--)
_putchar(hex[i]);
return (count + 2);
}
