#include "holberton.h"
/**
 * _print_env - Prints environment variables
 * @av: Received command
 * @env: all envment variables for the user
 *
 * Description: Prints all environment variables
 * Return: 1 if success
 */
int _print_env(char *av, char **env)
{
	unsigned int i = 0, length;
	char *s = "env";

	for (; av[i] > 96 && av[i] < 123 && av[i] == s[i]; i++)
		;
	if (i == 3)
	{
		i = 0;
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
