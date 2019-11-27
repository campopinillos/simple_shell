#include "holberton.h"
/**
 * _path - Find path
 * @av: Double pointer to free
 * @env: Environment
 * @av_0: Command
 * @l_av: Integer lenght command
 * @p_find: Integer pointer
 *
 * Description: Find path
 * Return: Nothing
 */
void _path(char **av, char *env, char *av_0, int l_av, int *p_find)
{
	int j = 0, start, c_path = 0;
	char *s = "PATH", *exev, **path;

	for (j = 0; env[j] == s[j] && env[j] != '='; j++)
		;
	if (j == 4)
		*p_find = 1;
	start = ++j;
	if (*p_find)
	{
		for (; env[j]; j++)
		{
			if (env[j] == ':')
				c_path++;
		}
		path = malloc(sizeof(char *) * (c_path + 2));
		exev = path[_findX(c_path, &env[start], av_0, l_av, start, path)];
		if (!exev)
		{
			_free(path);
			return;
		}
		j = _strlen(exev);
		free(av[0]);
		av[0] = malloc(sizeof(char) * (j + 1));
		j = 0;
		while (exev[j])
			av[0][j] = exev[j], j++;
		av[0][j] = '\0';
		j = 0;
		while (path[j] != '\0')
			free(path[j++]);
		free(path);
	}
}
