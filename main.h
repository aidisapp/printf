#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_string(char *args);
void print_char(char arg);
int print_format(char format_spec, va_list args);
int _putchar(char c);

#endif
