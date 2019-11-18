#include"holberton.h"

void exception (int signum)
{ 
    write(STDOUT_FILENO,"\n$ ",3);
}

int main (int argc, char **argv)
{
	(void) argc;
	char *buffer, **av;
	size_t s_buffer = 1;
	ssize_t lenght;
	int i = 0;
	pid_t child_pid;
	int num;

	printf("$ ");
	signal(SIGINT, exception);
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
		av = strtow(buffer);
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
