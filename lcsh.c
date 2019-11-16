#include"holberton.h"

int main (int argc, char **argv)
{
	(void) argc;
	char *buffer, **av;
	size_t s_buffer = 1;
	ssize_t lenght;
	int i = 0;

	printf("$ ");
	buffer = malloc(sizeof(char) * s_buffer);
	if (!buffer)
		return(0);
	while ((lenght = getline(&buffer, &s_buffer, stdin)) != -1)
	{
		av = strtow(buffer);
		for (; av[i] != '\0'; i++)
			printf("%s", av[i]);	
		printf("av set");
		_execve(av, argv[0]);
	}
	free(buffer);
	return (lenght);
}
