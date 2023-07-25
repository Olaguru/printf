#include "main.h"

/**
 * _printf - formats and prints data
 *
 * @format: a character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, char_count = 0, check;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	for (; format[i] != '\0'; i++)
	{
		/* for nomal characters */
		if (format[i] != '%')
		{
			char_count += _putchar(format[i]);
			continue;
		}
		/* for '%%' */
		if (format[++i] == '%')
		{
			char_count += _putchar('%');
			continue;
		}
		/* checks for %[possible specifier] */
		check = match_spec(format[i], args);
		/* if no specifier is found */
		if (check == -1)
		{
			char_count += _putchar(format[i - 1]);/*prints %*/
			char_count += _putchar(format[i]);/*then non-specifier character*/
		}
		else
			char_count += check;
	}
	va_end(args);
	return (char_count);
}
