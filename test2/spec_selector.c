#include "main.h"
/**
 * spec_select - matches a selected specifier
 *
 * @sw: specifier to be selected
 * @myargs: argument pointer that holds the value to be printed
 * Return: -1 if a specifier is not found. Otherwise any other number
*/
int spec_select(char sw, va_list myargs)
{
	int i = 0;

	specfunc matchspec[] = {
		/*{"d", print_int},
		{"i", print_int},*/
		{"s", _printstring},
		/*{"S", np_characters},*/
		{"c", _printchar},
		/*{"b", to_binary},
		{"u", print_unsigned_int},
		{"o", print_unsigned_oct},
		{"x", hex_lower},
		{"X", hex_UPPER},
		{"p", print_address},
		{"R", rot13},
		{"r", reverse_string},*/
		{NULL, NULL},
	};

	for (i = 0; matchspec[i].specifier; i++)
	{
		if (sw == *(matchspec[i].specifier))
			return (matchspec[i].ptr(myargs));
	}
	return (-1);
}
