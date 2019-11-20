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
	int cont = 1, e = 0;

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
		if (!av || av[0] == NULL)
		{
			printf("$ ");
			continue;
		}
		if (!av[1])
			e = _exitt(av[0]);
		if (open(av[0], O_RDONLY) != -1 && e)
			_execve(av), cont++;
		else
		{
			printf("%s: %i: %s: not found\n", argv[0], cont, av[0]);
			if (isatty(STDIN_FILENO))
				printf("$ ");
			cont++;
		}
	}
	free(buffer);
	return (-1);
}
