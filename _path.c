#include "holberton.h"
/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Firts input pointer
 * @old_size: Second input unsigned int
 * @new_size: Third input unsigned int
 *
 * Description: Reallocates a memory block
 * Return: String
 */
void *_realloc(void *ptr, int old_size, int new_size)
{
	char *p, *reserv;
	int i = 0;

	if (old_size == new_size)
		return (ptr);
	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	p = (void *) malloc(new_size);
	if (!p)
		return (NULL);
	if (!ptr)
		return (p);
	reserv = ptr;
	while (i < old_size)
	{
		p[i] = reserv[i];
		i++;
	}
	free(ptr);
	return (p);
}

void _path(char **av, char *env)
{
	int j = 0, z = 0,len_p = 0, k = 0;
	int row, start, old_size, len_av = 0, new_len;
	char *path;
	char *s = "PATH";

	for (j = 0; env[j] == s[j] && env[j] != '='; j++)
		;
	start = ++j;

	for (;env[start] != ':' && env[start] != '\0'; start++ , len_p++)
		;
	for (;av[0][len_av]; len_av++)
		;
	new_len = len_av + len_p + 1;
	path = malloc(sizeof(char) * (new_len + 1));
	/* Llenando path con la env carpeta */
	for (k = 0; env[j] != ':'; k++, j++)
		path[k] = env[j];
	path[j++] = '/';
	/* Llenando path con el av commando */
	for (z = 0; av[0][z]; z++, k++)
		path[k] = av[0][z];
	path[k] = '\0';

	_realloc(av[0], len_av, new_len);

	for (j = 0; path[j]; j++)
		av[0][j] = path[j];
}