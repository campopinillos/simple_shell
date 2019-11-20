#include "holberton.h"
/**
 *_exitt - handle exit command
 *@av: string
 *Return: void
 */
int _exitt(char *av)
{
	char *s = "exit";
	int i = 0;

	for (; av[i] > 96 && av[i] < 123 && av[i] == s[i]; i++)
		;
	if (i == 4)
		exit(0);
	return (1);
}
