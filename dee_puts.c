#include "main.h"
/**
 * dee_puts - prints a string to stdout
 *
 * @str: argument pointer to string
 * Return: number of characters printed
 */
int dee_puts(char *str)
{
	int i, count_char = 0;

	if (!str)
		str = "(null)";

	if (*str == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		count_char += my_putchar(str[i]);
		i++;
	}
	return (count_char);
}
