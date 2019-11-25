#include "holberton.h"

void _path(char **av, char *env, char *av_0, int l_av, int *p_find)
{
	int j = 0, start, c_path = 0;
	char *s = "PATH", *exev, **path;
	
	// PATH?
	for (j = 0; env[j] == s[j] && env[j] != '='; j++)
		;
	if (j == 4)
		*p_find = 1;
	start = ++j;
	if(*p_find)
	{
		//cont de carpetas dentro de path
		for (; env[j]; j++)
		{
			if (env[j] == ':')
				c_path++;
		}
		path = malloc(sizeof(char *) * (c_path + 2));
		exev = path[_find_X(c_path, &env[start], av_0, l_av, start, path)];
		if (!exev)
		{
			j = 0;
			while (path[j])
				free(path[j++]);
			free(path);
			return;
		}
		j = 0;
		while(exev[j] != '\0')
			j++;
		free(av[0]);
		av[0] = malloc(sizeof(char) * (j + 1));
		j = 0;
		while(exev[j])
			av[0][j] = exev[j], j++;
		av[0][j] = '\0';
		j = 0;
		while (path[j] != '\0')
			free(path[j++]);
		free(path);
	}
}
