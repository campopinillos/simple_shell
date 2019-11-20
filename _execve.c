#include "holberton.h"
/**
 * _execve - Call execve
 * @av: Double char pointer
 * Description: Call execve
 * Return: 1 if succes and -1 if fails
 */
int _execve(char **av)
{
	pid_t child_pid = 0;
	int num, i = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(av[0], av, NULL);
		while (av[i])
			free(av[i++]);
		free(av);
	}
	else
	{
		wait(&num);
		printf("$ ");
	}
	return (1);
}
