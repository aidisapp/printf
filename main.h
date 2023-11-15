#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
* struct specifier - structure definition for specifier and function pointers.
* @c: the specifier character, passed after the % symbol.
* @func_ptr: the functions associated to the specifier.
*/

typedef struct specifier
{
char *c;
int (*func_ptr)(va_list);
} spc_t;

int _printf(const char *format, ...);
int _putchar(char c);

int print_char(va_list args);
int print_string(va_list args);
int print_percentage(va_list args);
int print_dec_int(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_str_ASCII(va_list args);

#endif
