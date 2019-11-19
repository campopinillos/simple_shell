#include "holberton.h"

void _execve(char **av, char *argv)
{
	int r, i = 0;
	pid_t my_pid = 0;

	r = execve(av[0], av, NULL);

	if (getpid())
		my_pid++;
	if(r == -1)
		printf("%s %u: No such file or directory\n$ ", argv, my_pid);
	while(av[i])
		free(av[i++]);
	free(av);
	return;
}
