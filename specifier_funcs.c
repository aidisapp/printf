#include "main.h"

/**
* print_char - function to print a single character
* @args: character to print from the variable arguement list
* Return: the character to print
*/
int print_char(va_list args)
{
return (_putchar(va_arg(args, int)));
}

/**
* print_string - function to print strings
* @args: string to print from the variable argument list
* Return: strings to print
*
*/

int print_string(va_list args)
{
char *str = va_arg(args, char *);
int chars = 0, i;

if (!str)
{
	chars += write(1, "(null)", 6);
	return (chars);
}

for (i = 0; str[i] != '\0'; i++)
	chars += write(1, &str[i], 1);

return (chars);
}

/**
* print_percentage - function to print percentage
* @args: string to print from the variable argument list
* Return: if % is passed after the specifier
*
*/

int print_percentage(va_list args)
{
int chars = 0;
char *str = "%";

if (va_arg(args, int) == *str)
	chars = write(1, str, 1);
else
	chars = write(1, str, 1);

return (chars);
}

/**
* print_dec_int - function to print decimmal (signed) integer values
* @args: decimal argument from the variable list arguement
* Return: counter
*/

int print_dec_int(va_list args)
{
int num = va_arg(args, int);
unsigned int abs_val, divisor, dig_count, char_count = 0;

if (num < 0)
{
	abs_val = (num * -1);
	char_count += write(1, "-", 1);
}
else
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
* print_int - prints integer
* @args: integer argument
* Return: the decimal function
*/

int print_int(va_list args)
{
return (print_dec_int(args));
}
