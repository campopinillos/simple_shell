#include<stdlib.h>
/**
 *fill - fill the array
 *@str: string from
 *@p: string to
 *Return: void;
 */
void fill(char *str, char *p)
{
	int i = 0;

	for (; str[i] != ' ' && str[i] != '\0'; i++)
		p[i] = str[i];
	p[i] = '\0';
}
/**
 *strtow - cut a string
 *@str: string from
 *Return: p;
 */
char **strtow(char *str)
{
	char **p;
	int i = 0, cont = 0, cl = 0, cp = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			cont = cont + 1;
		if (str[i] != ' ' && str[i + 1] == '\0')
			cont = cont + 1;
	}
	p = malloc(sizeof(char *) * (cont + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0' && cp < cont; i++)
	{
		for (; str[i] != ' ' && str[i] != '\0'; i++)
			cl = cl + 1;
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
	if (cont == 0)
		p = NULL;
	else
		p[cp] = NULL;
	return (p);
}
