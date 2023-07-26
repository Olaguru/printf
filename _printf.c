#include "main.h"
/**
 * _printf - print formated text to output
 *
 * @format: the formated string
 * Return: the no of bytes
 */
int _printf(const char *format, ...)
{
	unsigned int pret = 0, ij, count;

	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	for (ij = 0; format[ij] != '\0'; ij++)
	{
		if (format[ij] != '%')
		{
			my_putchar(format[ij]);
		}
		else if (format[ij] == '%' && format[ij + 1] == 'c')
		{
			my_putchar(va_arg(args, int));
			ij++;
		}
		else if (format[ij] == '%' && format[ij + 1] == 's')
		{
			count = dee_puts(va_arg(args, char *));
			pret += count;
			ij++;
		}
		else if (format[ij] == '%' && (format[ij + 1] == '%'))
		{
			my_putchar('%');
			ij++;
		}
		else if (format[ij] == '%' && format[ij + 1] != '%')
		{
			my_putchar('%');
		}
		pret += 1;
	}
	va_end(args);
	return (pret);
}
