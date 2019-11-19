#include "holberton.h"
/**
 * _prompt - Executes orders
 * @argv: Double char pointer
 *
 * Description: Executes orders
 * Return: 1 if succes and -1 if fails
 */
ssize_t _prompt(char **argv)
{
	char *buffer, **av;
	size_t s_buffer = 1;
	ssize_t lenght;
	int i = 0, n = 0, cont = 1;

	printf("$ ");
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
		if(open(av[0], O_RDONLY) != -1)
			_execve(av);
		else
		{
			printf("%s %i: No such file or directory\n$ ", argv[0], cont);
			cont++;
		}
	}
	free(buffer);
	return (lenght);
}
