#include <unistd.h>

/**
 * _putchar - this fucntion writes a character to the standard output (stdout)
 *
 * @c: This is the character to be written
 *
 * Return: On success, it returns the character written as an
 *
 * unsigned char cast to an int
 *
 * On error, returns -1 and sets errno accordingly.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
