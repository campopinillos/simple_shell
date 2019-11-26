#include "holberton.h"
/**
 * _fill - Fill a string
 * @to: Double pointer destination
 * @from: String origin
 *
 * Description: Fill a string
 * Return: Nothing
 */
void _fill(char **to, char *from)
{
	int j = 0;

	while (from[j])
		to[0][j] = from[j], j++;
	to[0][j] = '\0';
}
