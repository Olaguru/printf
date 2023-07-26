#include "main.h"
/**
 * print_character - writes the character c to stdout
 * @c: argment pointer to the character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_character(va_list c)
{
	char ch = va_arg(c, int);

	return (write(1, &ch, 1));
}
