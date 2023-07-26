#include "main.h"
/**
 * string_printer - prints a string to stdout
 *
 * @str: argument pointer to string
 * Return: number of characters printed
 */
int string_printer(va_list str)
{
	int i, count_char = 0;
	char *tempo = va_arg(str, char *);

	if (!tempo)
		tempo = "(null)";
	if (*tempo == '\0')
		return (0);
	i = 0;
	while (tempo[i] != '\0)
	{
		count_char += my_putchar(tempo[i]);
		i++;
	}
	return (count_char);
}
