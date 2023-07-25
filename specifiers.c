#include "main.h"
#include <unistd.h>

/**
 * to_binary - converts an integer to binary
 *
 * @arg: argument pointer to int to be converted
 * Return: On success 0
 */
int to_binary(va_list arg)
{
	int i = 0, j, char_count = 0, binary_num[32];
	char c;
	unsigned int n;

	n = va_arg(arg, int);
	if (n == 0)
		return (_putchar(0 + '0'));
	while (n > 0)
	{
		binary_num[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		c = binary_num[j] + '0';
		char_count += _putchar(c);
	}
	return (char_count);
}

/**
 * print_unsigned_int - prints an unsigned integer
 *
 * @arg: argument pointer to integer
 * Return: number of characters printed
 */
int print_unsigned_int(va_list arg)
{
	int i, digit, char_count = 0, digits = 0, divisor = 1;
	char digit_char;
	unsigned int n, temp;

	n = va_arg(arg, int);
	if (n == 0)
		return (_putchar(0 + '0'));

	temp = n;
	while (temp)
	{
		temp /= 10;
		digits++;
	}
	for (i = 1; i < digits; i++)
		divisor *= 10;
	for (i = digits - 1; i >= 0; i--)
	{
		digit = n / divisor;
		digit_char = digit + '0';
		char_count += _putchar(digit_char);
		n %= divisor;
		divisor /= 10;
	}
	return (char_count);
}

/**
 * print_unsigned_oct - represents an integer in unsigned octal
 *
 * @arg: argument pointer to inetger
 * Return: number of characters printed
 */
int print_unsigned_oct(va_list arg)
{
	char oct_num[100];
	unsigned int i = 0, num;
	int char_count = 0;

	num = va_arg(arg, int);
	if (num == 0)
		return (_putchar(0 + '0'));
	do {
		oct_num[i++] = (num % 8) + '0';
		num /= 8;
	} while (num);

	while (i--)
		char_count += _putchar(oct_num[i]);
	return (char_count);
}

/**
 * hex_lower - represents an integer in unsigned hexadecimal (lowercase)
 *
 * @arg: argument pointer to inetger
 * Return: number of characters printed
 */
int hex_lower(va_list arg)
{
	int char_count = 0;
	unsigned int n = va_arg(arg, int);

	char_count = print_hex(n, 'a');
	return (char_count);
}

/**
 * hex_UPPER - represents an integer in unsigned hexadecimal (uppercase)
 *
 * @arg: argument pointer to inetger
 * Return: number of characters printed
 */
int hex_UPPER(va_list arg)
{
	int char_count = 0;
	unsigned int n = va_arg(arg, int);

	char_count = print_hex(n, 'A');
	return (char_count);
}
