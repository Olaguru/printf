#include "main.h"
#include <stdint.h>

/**
 * print_hex - prints an integer in unsigned hexadecimal
 *
 * @n: integer to be converted
 * @form: deteremines what case (lower or upper) in hex to be printed
 * Return: number of characters printed
*/
int print_hex(unsigned int n, int form)
{
	long int i = 0, j = 0, k, remainder;
	unsigned int val;
	char *ptr;

	val = n;
	if (n == 0)
		return (_putchar('0'));
	/* to get length of output */
	for (; val > 0; i++)
		val /= 16;

	/* malloc space to keep remainder */
	ptr = malloc(sizeof(char) * i);
	if (ptr == NULL)
		return (-1);

	/*putting each character in malloc'ed space*/
	for (; j < i; j++)
	{
		remainder = n % 16;
		if (remainder < 10)
			ptr[j] = remainder + 48;
		else
			ptr[j] = remainder - 10 + form;
		n /= 16;
	}
	/* printing in reverse */
	for (k = j - 1; k >= 0; k--)/* -1 from j because j = i */
		_putchar(ptr[k]);
	free(ptr);
	return (i);
}

/**
 * print_address - prints address contained in a pointer
 *
 * @arg: argument pointer to address
 * Return: number of characters printed
*/
int print_address(va_list arg)
{
	int i = 0, k, char_count = 0, size, check = 0;
	uintptr_t add = (uintptr_t)va_arg(arg, void *);
	char *ptr;
	unsigned int remainder;

	if (!add)
		return (_puts("(nil)"));
	/* starts printing with these */
	char_count += _puts("0x");
	size = sizeof(uintptr_t) * 2;

	/* malloc space to keep remainder */
	ptr = malloc(size);
	if (ptr == NULL)
		return (-1);
	/*putting each character in malloc'ed space*/
	for (; i < size; i++)
	{
		remainder = add % 16;
		if (remainder < 10)
			ptr[i] = remainder + 48;
		else
			ptr[i] = remainder - 10 + 'a';
		add /= 16;
	}
	/* printing in reverse */
	for (k = i - 1; k >= 0; k--)/* -1 from i because i = size */
	{
		/* check is set to 1 to remove leading 0's */
		if (ptr[k] != '0' || check == 1)
		{
			char_count += _putchar(ptr[k]);
			if (ptr[k] != '0')
				check = 1;
			else
				check = check;
		}
	}
	free(ptr);
	return (char_count);
}

/**
 * rot13 - encodes a string using rot13
 *
 * @arg: argument pointer to array of characters
 * Return: number of characters printed
 */
int rot13(va_list arg)
{
	int i, j, len;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot_code = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(arg, char *), *dup;

	if (!s)
		return (_puts(s));

	/* get length of @s and duplicate */
	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1)); /* +1 for null terminator */
	if (!dup)
		return (-1);

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (s[i] == alpha[j])
			{
				dup[i] = rot_code[j]; /* encode using rot13 */
				break;
			}
			dup[i] = s[i]; /* copy other regular characters */
		}
	}
	dup[i] = '\0';
	return (_puts(dup));
}

/**
 * np_characters - prints a string to stdout and handles conversion
 * specifier for non-printable characters, coverting them to hex
 *
 * @str: argument pointer to string
 * Return: number of characters printed
 */
int np_characters(va_list str)
{
	int i, char_count = 0;
	char *temp = va_arg(str, char *);

	if (!temp)
		temp = "(null)";
	/*for empty string*/
	if (*temp == '\0')
		return (0);
	for (i = 0; temp[i] != '\0'; i++)
	{
		/* for the %S specifier (non-printable charaters) */
		if ((temp[i] > 0 && temp[i] < 32) || temp[i] >= 127)
		{
			char_count += _putchar('\\');
			char_count += _putchar('x');
			/* to ensure hex value of 2 characters. */
			/* Decimal values >= 16 and < 32 already have two */
			/* characters when converted to hex */
			if (temp[i] < 16)
				char_count += _putchar('0');
			char_count += print_hex(temp[i], 'A');
			continue;
		}
		else
		char_count += _putchar(temp[i]);
	}
	return (char_count);
}

/**
 * reverse_string - prints a string in reverse
 *
 * @arg: argument pointer to string
 * Return: number of characters printed
*/
int reverse_string(va_list arg)
{
	int index, char_count = 0, len;
	char *s = va_arg(arg, char *);

	if (!s)
		return (_puts(s));

	/* get length of @s */
	len = _strlen(s);

	for (index = len - 1; index >= 0; index--)
		char_count += _putchar(s[index]);

	return (char_count);
}
