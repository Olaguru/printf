#include "main.h"
/**
 * _printf - print formatted string
 *
 * @format: a character string
 * Return: number of bytes (character printed)
 */
int _printf(const char *format, ...)
{
	int i, count_char = 0, checker;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count_char += my_putchar(format[i]);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			count_char += my_putchar('%');
			continue;
		}

		checker = spec_match(format[i], args);
		if (check == -1)
		{
			count_char += my_putchar(format[i--]);
			count_char += my_putchar(format[i]);
		}
		else
			count_char += checker;
	}
	va_end(args);
	return (count_char);
}
