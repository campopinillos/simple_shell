#include "holberton.h"
/**
 * _free - Free double pointer
 * @s: Double pointer to free
 *
 * Description: Free double pointer
 * Return: Nothing
 */
void _free(char **s)
{
	int j = 0;

	while (s[j])
		free(s[j++]);
	free(s);
}
