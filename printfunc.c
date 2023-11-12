#include "main.h"

/**
 * print_string - Print the string data type
 * @args: variadic list of strings
 */
void print_string(char *args)
{
  if (!args)
    write(STDOUT_FILENO, "(nil)", 5);
  else
    write(STDOUT_FILENO, args, strlen(args));
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
 * print_error - Print error and exit
 */
void print_error(void)
{
  write(STDERR_FILENO, "Error: Invalid format\n", 24);
  exit(EXIT_FAILURE);
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
  {
    print_error();
  }

  va_start(args, format);

  while (*format)
  {
    if (*format == '%')
    {
      format++;

      if (*format == '%')
      {
        write(STDOUT_FILENO, "%", 1);
      }
      else
      {
        switch (*format)
        {
        case 's':
          print_string(va_arg(args, char *));
          break;
        case 'c':
          print_char(va_arg(args, int));
          break;
        default:
          print_error();
        }
      }
    }
    else
    {
      chars += write(STDOUT_FILENO, format, 1);
    }

    format++;
  }

  va_end(args);

  return (chars);
}
