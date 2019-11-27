#include "holberton.h"
/**
 * _print_number - Print an integer
 * @n: Parameter input
 *
 * Description: Print an integer
 * Return: Nothing
 */
void _print_number(int n)
{
	unsigned int num = n;
	char c;

	if (num / 10 != 0)
		_print_number(num / 10);
	c = ((num % 10) + '0');
	write(STDERR_FILENO, &c, 1);
}
