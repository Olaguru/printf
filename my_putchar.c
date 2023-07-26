#include "main.h"
/**
 * my_putchar - prints a character
 *
 * @ch: character input
 * Return: 1
 */
int my_putchar(char ch)
{
	return (write(1, &ch, 1));
}
