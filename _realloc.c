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
	(void)old_size;
	ptr = malloc(sizeof(char) * new_size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
