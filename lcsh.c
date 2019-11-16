#include"holberton.h"

int main (void)
{
	char *buffer;
	size_t s_buffer = 1;
	ssize_t lenght;

	printf("$ ");
	buffer = malloc(sizeof(char) * s_buffer);
	if (!buffer)
		return(0);
	while ((lenght = getline(&buffer, &s_buffer, stdin)) != -1)
	{
		printf("%i", lenght);
		printf("%s$ ", buffer);
	}

	printf("\n");
	free(buffer);
	return (lenght);
}
