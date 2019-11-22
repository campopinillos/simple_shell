#include "holberton.h"
/**
 * _prompt - Executes orders
 * @argv: Double char pointer
 * @flag: Set interactive mode
 * Description: Executes orders
 * Return: 1 if succes and -1 if fails
 */
ssize_t _prompt(char **argv, int *flag, char **env)
{
	char *buffer, **av;
	size_t s_buffer = 1;
	ssize_t lenght;
	int cont = 1, e = 0, i = 0, j = 0;

	if (isatty(STDIN_FILENO))
		printf("$ "), *flag = 0;
	buffer = malloc(sizeof(char) * s_buffer);
	if (!buffer)
		return (0);
	while ((lenght = getline(&buffer, &s_buffer, stdin)) != -1)
	{
		if (lenght == EOF)
		{
			free(buffer);
			return (-1); }
		av = _strtok(buffer);
		if (!av)
		{
			printf("$ ");
			continue;
		}
		_exitt(av[0]);
		if (access(av[0], X_OK) == 0)
			_execve(av), cont++;
		else if (av)
		{
			j = 0;
			while(env[j] && access(av[0], X_OK) != 0)
				_path(av, env[j++]);
			if (access(av[0], X_OK) == 0)
				_execve(av), cont++;
		}
		else
		{
			printf("%s: %i: %s: not found\n", argv[0], cont, av[0]);
			cont++;
			i = 0;
			while (av[i])
				free(av[i++]);
			free(av);
			if (isatty(STDIN_FILENO))
				printf("$ ");
		}
	}
	free(buffer);
	return (-1);
}
