#include "main.h"
/**
 * print_hexadecimal - prints an integer in unsigned hexadecimal
 *
 * @n: integer to be converted
 * @formaat: deteremines what case (lower or upper) in hex to be printed
 * Return: number of characters printed
*/
int print_hexadecimal(unsigned int n, int formaat)
{
	long int i, j, k, remainder;
	size_t val;
	char *ptr;

	val = n;
	if (n == 0)
		return (my_putchar('0'));

	for (i = 0; val > 0; i++)
		val /= 16;

	ptr = malloc(sizeof(char) * i);
	if (ptr == NULL)
		return (-1);

	for (j = 0; j < i; j++)
	{
		remainder = n % 16;
		if (remainder < 10)
		{
			ptr[j] = remainder + 48;
		}
		else
			ptr[j] = remainder - 10 + formaat;
		n /= 16;
	}

	k = j - 1;
	while (k >= 0)
	{
		my_putchar(ptr[k]);
		k--;
	}
	free(ptr);
	return (i);
}
