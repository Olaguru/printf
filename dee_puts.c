#include "main.h"
/**
 * dee_puts - print a string and
 * act as a standard put function
 * @string: the strings to be printed
 * of type char
 * Return: no of byte
 */
int dee_puts(char *string)
{
	int count_char = 0;

	if (string)
	{
		for (count_char = 0; string[count_char] != '\0'; count_char++)
		{
			my_putchar(string[count_char]);
		}
	}
	return (count_char);
}
