#include "main.h"
/**
 * _printchar - write a character to the stdout
 *
 * @c: character to collect and print out
 * Return: no of character printed
 */
int _printchar(va_list c)
{
	char character = va_arg(c, int);

	return(write(1, &character, 1));
}
