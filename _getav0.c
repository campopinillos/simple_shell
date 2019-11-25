#include "holberton.h"

void  _getav0(int *l_av, char **av, char *av_0)
{
	int i = 0;

	i = 0;
	while(av[0][i])
		av_0[i] = av[0][i], i++;
	av_0[i] = '\0';
	*l_av = i;
}

