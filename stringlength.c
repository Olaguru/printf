#include "main.h"

/**
 * stringlen - computes the length of a string excluding null byte
 *
 * *string: pointer to string input
 * Return: returns the length of a string
 */
int stringlen(char *string)
{
	int it;

	it = 0;
	while (string[it] != '\0')
	{
		it++;
	}

	return (it);
}
