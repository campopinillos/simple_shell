#include "holberton.h"

ssize_t _prompt(char **argv)
{
	char *buffer, **av;
	ssize_t lenght;
	size_t s_buffer = 1;
	pid_t child_pid;
	int num;
	
	printf("$ ");

	signal(SIGINT, _signalc);
	buffer = malloc(sizeof(char) * s_buffer);
	if (!buffer)
		return(0);
	while ((lenght = getline(&buffer, &s_buffer, stdin)) != -1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
        	perror("Error:");
        	return (1);
		}
		av = _strtok(buffer);
		free(buffer);
		if (child_pid == 0)
			_execve(av, argv[0]), free(av);
		else
		{
			wait(&num);
			printf("$ ");
		}		
	}
	free(buffer);
	return (lenght);
}