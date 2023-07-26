#include "main.h"
/**
 * spec_match - matches a specifier to its function
 *
 * @ch: specifier to be matched
 * @args: argument pointer that holds the value to be printed
 * Return: -1 if a specifier is not found. Otherwise any other number
*/
int match_spec(char ch, va_list args)
{
	int it;

	cf ipe[] = {
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"S", characters_np},/*done*/
		{"c", print_char},
		{"b", to_binary},
		{"u", print_unsigned_int},
		{"o", print_unsigned_oct},
		{"x", hex_lower},
		{"X", hex_UPPER},
		{"p", print_adress_me},/*done*/
		{"R", 13rot},/*done*/
		{"r", rev_string},/*done*/
		{NULL, NULL},
	};

	for (it = 0; ipe[it].c; it++)
	{
		if (ch == *(ipe[it].c))
			return (ipe[it].ptr(args));
	}
	return (-1);
}
