#include "holberton.h"
/**
 * _prompt - Executes orders
 * @argv: Double char pointer
 * @flag: Set interactive mode
 * Description: Executes orders
 * Return: 1 if succes and -1 if fails
 */
ssize_t _prompt(char **argv, int *flag)
{
	char *buffer, **av;
	size_t s_buffer = 1;
	ssize_t lenght;
	int cont = 1, e = 0, i = 0;
	struct stat sb;

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
		if (!av[1])
			e = _exitt(av[0]);
		if (open(av[0], O_RDONLY) != -1 && e)
		{
			cont++;
			if (stat(av[0], &sb) == 0)
				_execve(av);
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
