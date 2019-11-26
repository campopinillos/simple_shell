#include "holberton.h"
/**
 * _print_error - Print error
 * @argv0: Shell name
 * @cont: Number error
 * @av0: Argument passed
 *
 * Description: Print error
 * Return: Nothing
 */
void _print_error(char *argv0, int cont, char *av0)
{
	int length;

	length = _strlen(argv0);
	write(STDOUT_FILENO, argv0, length);
	write(STDOUT_FILENO, ": ", 2);
	_print_number(cont);
	write(STDOUT_FILENO, ": ", 2);
	length = _strlen(av0);
	write(STDOUT_FILENO, av0, length);
	write(STDOUT_FILENO, ": not found\n", 12);
}
