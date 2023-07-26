#include "main.h"
/**
 * rev_string - prints a string in reverse
 *
 * @arg: argument pointer to string
 * Return: number of characters printed
*/
int rev_string(va_list arg)
{
	int index, count_char = 0, len;
	char *s = va_arg(arg, char *);

	if (!s)
		return (dee_puts(s));

	len = stringlen(s);

	index = len - 1;
	while (index >= 0)
		char_count += my_putchar(s[index]);
	index--;

	return (count_char);
}
