#include "holberton.h"
/**
 * _execve - Call execve
 * @av: Double char pointer
 * @argv: Char pointer
 *
 * Description: Call execve
 * Return: 1 if succes and -1 if fails
 */
int _execve(char **av, char *argv)
{
	int r;
	pid_t my_pid = 0;

	r = execve(av[0], av, NULL);

	if (getpid())
		my_pid++;
	if (r == -1)
	{
		printf("%s %u: No such file or directory\n$ ", argv, my_pid);
		return (-1);
	}
	return (1);
}
