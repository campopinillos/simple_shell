#include"holberton.h"

void _execve(char **av, char *argv)
{
	int r;

	r = execve(av[0], &av[0], NULL);
	if(r == -1)
	{
		printf("%s: No s file or directory", argv[0]);
		return;
	}
	return;
}
