#include "holberton.h"
/**
 * _exitt - Handle exit command
 * @av: string
 *
 * Description: Handle exit command
 * Return: Integer
 */
int _exitt(char *av)
{
	char *s = "exit";
	int i = 0;

	for (; av[i] > 96 && av[i] < 123 && av[i] == s[i]; i++)
		;
	if (i == 4)
	{
		free(av);
		exit(0);
	}
	return (1);
}
