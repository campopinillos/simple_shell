#include "holberton.h"
/**
 *_ifdir - checks if dir
 *@argv: argv
 *@av: argv lsh
 *@cont: error counter
 *Return: 1 - 0
 */
int _ifdir(char **argv, char **av, int *cont)
{
	DIR *d;

	d = opendir(av[0]);
	if (d)
	{
		_print_error(argv[0], *cont, av[0]);
		*cont = *cont + 1;
		_free(av);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
			closedir(d);
			return (1);
		}
		else
		{
			closedir(d);
			return (-1);
		}
		closedir(d);
	}
	return (0);
}
