#include "main.h"
/**
 * dee_puts - print string
 * @st: string input
 *
 * Return: no of byte of string printed
 */
int dee_puts(char *st)
{
	int i;

	for (i = 0; st[i] != '\0'; i++)
	{
		my_putchar(st[i]);
	}
	return (i);
}
