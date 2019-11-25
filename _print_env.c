#include "holberton.h"
/**
 * print_env - prints all of the envment variables to the output
 * @env: all envment variables for the user
 *
 * Return: void
 */
int _print_env(char *av, char **env)
{
	unsigned int i = 0, length;
	char *s = "env";

	for (; av[i] > 96 && av[i] < 123 && av[i] == s[i]; i++)
		;
	if (i == 3)
	{
		while (env[i])
		{
			length = _strlen(env[i]);
			write(STDOUT_FILENO, env[i], length);
			write(STDOUT_FILENO, "\n", 1);
			++i;
		}
	}
	return (1);
}
