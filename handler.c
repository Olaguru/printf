#include "main.h"
/**
 * handler - Format controller
 * @str: String format
 * @list: List of arguments
 *
 * Return: Total size of arguments with the total size of the base string
 **/
int handler(const char *str, va_list list)
{
	int size, i, aux;

	size = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			aux = percent_handler(str, list, &i);
			if (aux == -1)
				return (-1);

			size += aux;
			continue;
		}

		_putchar(str[i]);
		size = size + 1;
		i++;
	}

	return (size);
}
/**
 * percent_handler - Controller
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 *
 * Return: Size of the numbers of elements printed
 **/
int percent_handler(const char *str, va_list list, int *i)
{
	int size, number_formats;
	format formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexadecimal_low},
		{'X', print_hexadecimal_upp}, {'p', print_pointer},
		{'r', print_rev_string}, {'R', print_rot}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	switch (str[*i])
	{
	case '%':
		_putchar('%');
		size = 1;
		break;
	default:
		number_formats = sizeof(formats) / sizeof(formats[0]);
		for (size = 0; size < number_formats; size++)
		{
			if (str[*i] == formats[size].type)
			{
				size = formats[size].f(list);
				return (size);
			}
		}

		_putchar('%');
		_putchar(str[*i]);
		size = 2;
		break;
	}

	return (size);
}

