#include "main.h"
/**
 * _printf - print formated text to output
 *
 * @format: the formated string
 * Return: the no of bytes
 */
int _printf(const char *format, ...)
{
	unsigned int pret = 0, ij, count, di_count = 0;

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
			pret += (count - 1);
			ij++;
		}
		else if (format[ij] == '%' && (format[ij + 1] == '%'))
		{
			my_putchar('%');
			ij++;
		}
		else if (format[ij + 1] == 'd' || format[ij + 1] == 'i')
		{
			di_count += _putint(va_arg(args, int));
			ij++;
			pret += (di_count - 1);
		}
		else
		{
			my_putchar('%');
		}
		pret += 1;
	}
	va_end(args);
	return (pret);
}
