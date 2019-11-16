#include "holberton.h"

void _execve(char **av, char *argv)
{
	int r;
	extern char **environ;

	r = execve(av[0], av, environ);
	if(r == -1)
	{
		printf("%s: No such file or directory\n", argv);
		return;
	}
	return;
}
