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
	int my_printf_return = 0;
	unsigned int it;
	int s_add;

	va_list myargs;

	va_start(myargs, format);

	for (it = 0; format[it] != '\0'; it++)
	{
		if (format[it] != '%')
		{
			my_putchar(format[it]);
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
			my_printf_return += (s_add - 1);
		}
		else if (format[it + 1] == '%')
		{
			my_putchar('%');
			it++;
		}
		else if (format[it] == '%' && (format[it + 1] == 'd' || format[it + 1] == 'i' ))
		{
			s_add = put_int(va_arg(myargs, int));
			it++;
			my_printf_return += s_add;
		}
		else if (format[it] == '%' && format[it + 1] != '%')
		{
		       	my_putchar('%');
		}
		my_printf_return += 1;
	}
	va_end(myargs);
	return (my_printf_return);

}
