#include "holberton.h"
/**
 * _execve - Call execve
 * @av: Double char pointer
 * @num: num
 * Description: Call execve
 * Return: 1 if succes and -1 if fails
 */
int _execve(char **av, int *num)
{
	pid_t child_pid = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(av[0], av, NULL);
	}
	else
	{
		wait(num);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	_free(av);
	return (1);
}
