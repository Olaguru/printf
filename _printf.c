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
	int p_ret = 0;
	unsigned int it;
	int s_add;

	va_list myargs;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(myargs, format);

	for (it = 0; format[it] != '\0'; it++)
	{
		if (format[it] != '%')
		{
			my_putchar(format[it]);
		}
		else if (format[it + 1] == '%')
		{
			my_putchar('%');
			it++;
		}
		else if (format[it] == '%' && format[it + 1] == 'c')
		{
			my_putchar(va_arg(myargs, int));
			it++;
		}
		else if (format[it] == '%' && format[it + 1] == 's')
		{
			s_add = dee_puts(va_arg(myargs, char *));
			it++;
			p_ret += (s_add - 1);
		}
		else if (format[it] == '%' && format[it + 1] != '%')
		{
			my_putchar('%');
		}
		p_ret += 1;
	}
	va_end(myargs);
	return (p_ret);

}
