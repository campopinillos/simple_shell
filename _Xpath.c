#include "holberton.h"
/**
 *_Xpath - handle the path
 *@av: av
 *@p_find: p_find
 *@env: environment
 *@cont: count
 *@flag_1: flag
 *@num: num
 *Return: av_0
 */
char *_Xpath(char **av, int *p_find, char **env, int *cont,
	     int *flag_1, int *num)
{
	int i = 0, l_av, j;
	char *av_0;

	i = _strlen(av[0]), av_0 = malloc(sizeof(char) * (i + 1));
	_getav0(&l_av, av, av_0);
	for (j = 0; env[j] && access(av[0], X_OK) != 0 && *p_find == 0; j++)
		_path(av, env[j], av_0, l_av, p_find);
	if (access(av[0], X_OK) == 0)
		_execve(av, num), cont++, *flag_1 = 1, free(av_0);
	return (av_0);
}
