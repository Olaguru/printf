#include "main.h"
/**
 * put_int - print integers
 * using recursion
 *
 * @num: the number needed
 * Return: no of byte
 */
int put_int(int num)
{
	int bytes_returned = 0;

	if (num < 10)
	{
		my_putchar(num + '0');
		bytes_returned++;
	}
	else
	{
		bytes_returned = put_int(num / 10);
		my_putchar((num % 10) + '0');
		bytes_returned++;

	}

	return (bytes_returned);
}
