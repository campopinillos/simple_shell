#include "holberton.h"

void _fill(char **to, char *from)
{
	int j = 0;
	while(from[j])
		to[0][j] = from[j], j++;
	to[0][j] = '\0';
}
