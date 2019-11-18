#include "holberton.h"

ssize_t _prompt(char **argv)
{
	char *buffer, **av;
	size_t s_buffer = 1;
	ssize_t lenght;
 	pid_t child_pid;
 	int num;

 	printf("$ ");
 	buffer = malloc(sizeof(char) * s_buffer);
 	if (!buffer)
 		return(0);
 	while (1)
 	{
		lenght = getline(&buffer, &s_buffer, stdin);
		child_pid = fork();
 		if (child_pid == -1)
		{
        	perror("Error:");
         	return (1);
 		}
 		av = _strtok(buffer);
 		if (child_pid == 0)
 			_execve(av, argv[0]);
 		else
 		{
 			wait(&num);
 			printf("$ ");
 		}		
 	}
 	free(buffer);
	return (lenght);
}
