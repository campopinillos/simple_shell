#include "holberton.h"
void fill(char *str, char *p);
/**
 * _strtok - Cut a string by words
 * @str: string from
 *
 * Description: Cut a string by words
 * Return: A double char pointer p
 */
char **_strtok(char *str)
{
	char **p;
	int i = 0, cont = 0, cl = 0, cp = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (; str[i] != '\n'; i++)
		cont++;
	str[i] = '\0';
	p = malloc(sizeof(char *) * (cont + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0' && str[i] != '#' && cp < cont; i++)
	{
		for (; str[i] != ' ' && str[i] != '\0' && str[i] != 9 && str[i]; i++)
			cl++;
		if (cl > 0)
		{
			p[cp] = malloc(sizeof(char) * (cl + 1));
			if (p == NULL)
				return (NULL);
			fill((str + (i - cl)), p[cp]);
			cp++;
		}
		cl = 0;
	}
	if (cp == 0)
		free(p), p = NULL;
	else
		p[cp] = NULL;
	return (p);
}

/**
 * fill - Fill the string
 * @str: String from
 * @p: String to
 *
 * Description: Cut a string by words
 * Return: Void
 */
void fill(char *str, char *p)
{
	int i = 0;

	for (; str[i] != ' ' && str[i] != '\0' && str[i] != 9; i++)
		p[i] = str[i];
	p[i] = '\0';
}
