#include "main.h"
/**
 * print_address_me - prints address contained in a pointer
 *
 * @arg: argument pointer to address
 * Return: number of characters printed
*/
int print_address_me(va_list arg)
{
	int i, k, count_char = 0, size, checker = 0;
	uintptr_t add = (uintptr_t)va_arg(arg, void *);
	char *ptr;
	unsigned int remainder;

	if (!add)
		return (dee_puts("(nil)"));
	count_char += dee_puts("0x");
	size = sizeof(uintptr_t) * 2;

	ptr = malloc(size);
	if (ptr == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		remainder = add % 16;
		if (remainder < 10)
			ptr[i] = remainder + 48;
		else
			ptr[i] = remainder - 10 + 'a';
		add /= 16;
		i++;
	}
	k = i - 1;
	while (k >= 0)
	{
		if (ptr[k] != '0' || checker == 1)
		{
			count_char += my_putchar(ptr[k]);
			if (ptr[k] != '0')
			{
				checker = 1;
			}
			else
				checker = checker;
		}
		K--;
	}
	free(ptr);
	return (count_char);
}
