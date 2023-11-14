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
	{NULL, NULL}};

int count;

for (count = 0; spc_arr[count].c != NULL; count++)

{
	if (str == spc_arr[count].c[0])
	{
	return (spc_arr[count].func_ptr);
	}
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

int count = 0, i = 0;

int (*formatter)(va_list);

va_list args;
va_start(args, format);

if (!format || (format[0] == '%' && !format[1]))
	return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
	return (-1);

while (format[i] != '\0')
{
	if (format[i] == '%')
	{
	if (format[i + 1] == '%')
	{
		count += write(1, "%", 1);
		i += 2;
	}
	else
	{
		formatter = spc_func_ptr(format[i + 1]);
		if (formatter)
		count += formatter(args);
		else
		count += write(1, &format[i], 2);
		i += 2;
	}
	}
	else
	{
	count += write(1, &format[i], 1);
	i++;
	}
}

va_end(args);
return (count);
}
