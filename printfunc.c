#include "main.h"

/**
* spc_func_ptr - function to return a function pointer to a
* function accociated with the specifier
* @str: variable to the function
* Return: specified function
*/
int (*spc_func_ptr(char str))(va_list)
{
spc_t spc_arr[] = {
	{"c", print_char},
	{"s", print_string},
	{"%", print_percentage},
	{"d", print_dec_int},
	{"i", print_int},
	{"b", print_binary},
	{"u", print_unsigned},
	{"o", print_octal},
	{"x", print_hex_lower},
	{"X", print_hex_upper},
	{"S", print_str_ASCII},
	{"p", print_pointer},
	{"+", print_integer_positive},
	{" ", print_space_str},
	{"#", print_hash_specifier},
	{NULL, NULL}};

int count;

for (count = 0; spc_arr[count].c != NULL; count++)
{
	if (str == spc_arr[count].c[0])
	return (spc_arr[count].func_ptr);
}

return (NULL);
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
int chars = 0, count = 0;

int (*formatter)(va_list);

va_list args;
va_start(args, format);

if (!format || (format[0] == '%' && !format[1]))
	return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);

while (format[count] != '\0')
{
	if (format[count] == '%')
	{
	if (format[count + 1] == '%')
	{
		chars += write(1, "%", 1);
		count += 2;
	}
	else
	{
		formatter = spc_func_ptr(format[count + 1]);
		if (formatter)
		chars += formatter(args);
		else
		chars += write(1, &format[count], 2);
		count += 2;
	}
	}
	else
	{
	chars += write(1, &format[count], 1);
	count++;
	}
}

va_end(args);
return (chars);
}

