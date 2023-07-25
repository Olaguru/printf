#include "main.h"
/**
 * _printf - a function that produces output according to a format
 *
 * @format: format for the output
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	int p_ret = 0, s_add;
	unsigned int it;

	va_list myargs;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(myargs, format);

	for (it = 0; format[it] != '\0'; it++)
	{
		if (format[it] != '%')
		{
			p_ret += my_putchar(format[it]);
		}
		else if (format[it + 1] == '%')
		{
			p_ret += my_putchar('%');
			it++;
		}
		else if (format[it] == '%' && format[it + 1] == 'c')
		{
			p_ret += my_putchar(va_arg(myargs, int));
			it++;
		}
		else if (format[it] == '%' && format[it + 1] == 's')
		{
			s_add = dee_puts(va_arg(myargs, char *));
			it++;
			p_ret += (s_add);
		}
		else if (format[it] == '%' && (format[it + 1] != '%'))
		{
			p_ret += my_putchar('%');
		}
	}
	va_end(myargs);
	return (p_ret);
}
