#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
	char single_char = 'I';
	char string_char[] = "want";

	_printf("Custom Printf %%c and %%s: %c want to know %s you are doing\n", single_char, string_char);
	printf("Printf %%c and %%s: %c want to know %s you are doing\n", single_char, string_char);

	return (0);
}
