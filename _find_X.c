#include"holberton.h"
int _find_X(int c_path, char *env, char *av_0, int l_av, int start, char **path)
{
	int m = 0, st = 0, l_p = 0, j = 0, i = 0;
   	
	while(m <= c_path)
	{
		st = start;
		for(; env[start] && env[start] != ':'; start++, l_p++)
			;
		path[m] = malloc(sizeof(char) * (l_p + l_av + 2));
		for(l_p = 0; env[st] && env[st] != ':'; st++)
			path[m][l_p++] = env[st];
		path[m][l_p++] = '/';
		for (i = 0; av_0[i]; i++)
			path[m][l_p++] = av_0[i];
		path[m][l_p++] = '\0';
		start++, j++, m++;
	}
	path[m] = NULL;
	m = 0;
	while(path[m] != '\0' && access(path[m], X_OK) != 0)
		m++;
	return(m);
}	
