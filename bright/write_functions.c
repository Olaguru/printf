#include "main.h"
#include <unistd.h>
#include <limits.h>

/**
 * print_string - prints a string to stdout
 *
 * @str: argument pointer to string
 * Return: number of characters printed
 */
int print_string(va_list str)
{
	int i, char_count = 0;
	char *temp = va_arg(str, char *);

	if (!temp)
		temp = "(null)";
	/*for empty string*/
	if (*temp == '\0')
		return (0);
	for (i = 0; temp[i] != '\0'; i++)
		char_count += _putchar(temp[i]);
	return (char_count);
}

/**
 * _puts - prints a string to stdout
 *
 * @str: argument pointer to string
 * Return: number of characters printed
 */
int _puts(char *str)
{
	int i, char_count = 0;

	if (!str)
		str = "(null)";
	/*for empty string*/
	if (*str == '\0')
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		char_count += _putchar(str[i]);
	}
	return (char_count);
}

/**
 * print_int - prints an integer
 *
 * @arg: argument pointer to integer to be printed
 * Return: number of characters printed
 */
int print_int(va_list arg)
{
	int i, n, temp, digit, char_count = 0, digits = 0, divisor = 1;
	char digit_char;

	n = va_arg(arg, int);
	if (n == 0)
		return (_putchar(0 + '0'));
	if (n == INT_MIN)
	{
		char_count += _putchar('-');
		char_count += _putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		char_count += _putchar('-');
		n = -n;
	}
	temp = n;
	for (; temp; digits++)
		temp /= 10;
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
 * print_char - writes the character c to stdout
 * @c: argment pointer to the character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list c)
{
	char ch = va_arg(c, int);

	return (write(1, &ch, 1));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
