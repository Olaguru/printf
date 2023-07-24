#include "main.h"
/**
 * _printstring - prints a string to stdout
 *
 * @strng: argument pointer to string
 * Return: number of characters printed
 */
int _printstring(va_list strng)
{
	int i, str_count = 0;
	char *temporary = va_arg(strng, char *);

	if (!temporary)
		temporary = "(null)";
	/*for empty string we do this*/
	if (*temporary == '\0')
	{
		return (0);
	}
	for (i = 0; temporary[i] != '\0'; i++)
		str_count += my_putchar(temporary[i]);
	return (str_count);
}
