#include "main.h"
<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
=======
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
		else if (format[it] == '%' && format[it + 1] != '%')
		{
			p_ret += my_putchar('%');
		}
	}
	va_end(myargs);
	return (p_ret);
>>>>>>> 70892eead187163c72789992ea8faf18e9231bbb
}
