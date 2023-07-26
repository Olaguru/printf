#include "main.h"
/**
 * 13rot - encodes a string using rot13
 *
 * @arg: argument pointer to array of characters
 * Return: number of characters printed
 */
int 13rot(va_list arg)
{
	int i, j, len;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *code_rot = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(arg, char *), *dupe;

	if (!s)
		return (dee_puts(s));

	len = _strlen(s);
	dupe = malloc(sizeof(char) * (len + 1));
	if (!dupe)
		return (-1);

	i = 0;
	while (s[i] != '\0')
	{
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (s[i] == alpha[j])
			{
				dupe[i] = code_rot[j];
				break;
			}
			dupe[i] = s[i];
		}
		i++;
	}
	dupe[i] = '\0';
	return (dee_puts(dupe));
}
