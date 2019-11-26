#include "holberton.h"
/**
 * _getav0 - Get command
 * @l_av: Lenght pointer
 * @av: Double pointer
 * @av_0: Command
 *
 * Description: Get command
 * Return: Nothing
 */
void  _getav0(int *l_av, char **av, char *av_0)
{
	int i = 0;

	i = 0;
	while (av[0][i])
		av_0[i] = av[0][i], i++;
	av_0[i] = '\0';
	*l_av = i;
}

