#include <unistd.h>
/**
 * my_putchar - print a character
 * act as the conventional putchar
 *
 * @c: the character to print
 * Return: int
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}
