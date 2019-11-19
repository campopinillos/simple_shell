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
	pid_t child_pid;
	int num, i = 0;

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
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			free(buffer);
			return (1); }
		av = _strtok(buffer);
		if (child_pid == 0)
		{
			if ((_execve(av, argv[0])) == -1)
			{
				i = 0;
				while (av[i])
					free(av[i++]);
				free(av); }
		}
		else
		{
			wait(&num);
			printf("$ ");
			i = 0;
			while (av[i])
				free(av[i++]);
			free(av); } }
	free(buffer);
	return (lenght);
}
