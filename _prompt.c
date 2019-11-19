#include "holberton.h"

ssize_t _prompt(char **argv)
{
	char *buffer, **av, buff[1024];
	size_t s_buffer = 1;
	ssize_t lenght;
 	pid_t child_pid;
 	int num, i = 0;

 	printf("$ ");
 	buffer = malloc(sizeof(char) * s_buffer);
 	if (!buffer)
 		return(0);
 	while ((lenght = getline(&buffer, &s_buffer, stdin)) != -1)
 	{
		if(lenght == EOF)
		{
			free(buffer);
			return (-1);
		}
		child_pid = fork();
 		if (child_pid == -1)
		{
			perror("Error:");
			free(buffer);
			return (1);
 		}
 		av = _strtok(buffer);
		free(buffer);
		if (child_pid == 0)
 			_execve(av, argv[0]);
 		else
 		{
 			wait(&num);
 			printf("$ ");
			while (av[i])
				free(av[i++]);
 		}
		free(av);	
 	}
	return (lenght);
}
