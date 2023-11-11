#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct format_struct - This struct contains information on the format.
 * It defines two members which will be used in our program
 * @specifier: Character specified by the user to check for
 * @func_ptr: Pointer to function to
 */
typedef struct format_struct
{
	char *specifier;
	void (*func_ptr)();
} prt_fmt_t;

int _strlen(char *val);
int _printf(const char *format, ...);

#endif

