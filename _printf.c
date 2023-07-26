#include "main.h"
/**
 * _printf - print formatted text
 * @format: string format
 *
 * Return: no of byte
 **/
int _printf(const char *format, ...)
{
	int big_size;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	big_size = _strlen(format);
	if (big_size <= 0)
	{
		return (0);
	}

	va_start(args, format);
	size = handler(format, args);

	myputchar(-1);
	va_end(args);

	return (size);
}
