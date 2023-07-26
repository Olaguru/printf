#include "main.h"
/**
 * characters_np - prints a string to stdout and handles conversion
 * specifier for non-printable characters, coverting them to hex
 *
 * @str: argument pointer to string
 * Return: number of characters printed
 */
int characters_np(va_list str)
{
	int i, count_char = 0;
	char *tempo = va_arg(str, char *);

	if (!tempo)
	{
		tempo = "(null)";
	}
	if (*tempo == '\0')
		return (0);
	i = 0;
	while (tempo[i] != '\0')
	{
		if ((tempo[i] > 0 && tempo[i] < 32) || tempo[i] >= 127)
		{
			count_char += my_putchar('\\');
			count_char += my_putchar('x');

			if (tempo[i] < 16)
				count_char += my_putchar('0');
			count_char += print_hexadecimal(tempo[i], 'A');
			continue;
		}
		else
		count_char += my_putchar(tempo[i]);
		i++;
	}
	return (count_char);
}
