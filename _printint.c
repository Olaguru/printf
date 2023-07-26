#include "main.h"
/**
 * _printint - prints an integer
 *
 * @arg: argument pointer to integer to be printed
 * Return: number of characters printed
 */
int _printint(va_list arg)
{
	int i, n, temp, digit, count_char = 0, digits = 0, divisor = 1;
	char digit_char;

	n = va_arg(arg, int);
	if (n == 0)
		return (my_putchar(0 + '0'));
	if (n == INT_MIN)
	{
		count_char += my_putchar('-');
		count_char += my_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count_char += my_putchar('-');
		n = -n;
	}
	temp = n;
	for (; temp; digits++)
		temp /= 10;
	for (i = 1; i < digits; i++)
		divisor *= 10;
	i = digits - 1;
	while (i >= 0)
	{
		digit = n / divisor;
		digit_char = digit + '0';
		count_char += my_putchar(digit_char);
		n %= divisor;
		divisor /= 10;
		i--;
	}
	return (count_char);
}
