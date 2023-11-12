#include "main.h"

/**
* print_string - Print the string data type
* @args: variadic list of strings
*
* Return: formatted strings or nil
*/
int print_string(char *args)
{
int chars = 0;

if (!args)
	chars = write(STDOUT_FILENO, "(null)", 6);
else
	chars = write(STDOUT_FILENO, args, strlen(args));

return (chars);
}

/**
* print_char - Print the char data type
* @arg: variadic list char
*/
void print_char(char arg)
{
char str[2];

str[0] = arg;
str[1] = '\0';

write(STDOUT_FILENO, str, 1);
}

/**
* print_format - function to print the format string or error
* @format_spec: Format string specifier
* @args: variadic list format string
*
* Return: formatted string or error
*/
int print_format(char format_spec, va_list args)
{
int chars = 0;

if (format_spec == '%')
	chars += write(STDOUT_FILENO, "%", 1);
else if (format_spec == 's')
	chars += print_string(va_arg(args, char *));
else if (format_spec == 'c')
{
	print_char(va_arg(args, int));
	chars++;
}

return (chars);
}

/**
* _printf - a function that produces output according to a format.
* @format: List of types of arguments being passed
* @...: List of types of arguments being passed
*
* Return: the formatted output string, or error if format is null.
*/

int _printf(const char *format, ...)
{

va_list args;
int chars = 0;

if (!format)
	return (-1);

va_start(args, format);

while (*format)
{
	if (*format == '%')
	{
	if (strlen(format) == 2)
		write(STDOUT_FILENO, "%", 1);
	else
	{
		format++;
		chars += print_format(*format, args);
	}
	}
	else
	chars += write(STDOUT_FILENO, format, 1);

	format++;
}

va_end(args);
return (chars);
}
