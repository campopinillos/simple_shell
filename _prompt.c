#include "holberton.h"
/**
 * _prompt - Executes orders
 * @argv: Double char pointer
 * @flag: Set interactive mode
 * @env: environ
 *
 * Description: Executes orders
 * Return: 1 if succes and -1 if fails
 */
ssize_t _prompt(char **argv, int *flag, char **env)
{
	DIR *d;
	int cont = 1, i = 0, j = 0, l_av = 0, flag_1 = 0, p_find = 0;
	char *buffer, **av, *av_0;
	size_t s_buffer = 1;
	ssize_t lenght;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2), *flag = 0;
	buffer = malloc(sizeof(char) * s_buffer);
	if (!buffer)
		return (0);
	while ((lenght = getline(&buffer, &s_buffer, stdin)) != -1)
	{	p_find = 0, flag_1 = 0;
		if (lenght == EOF)
		{
			free(buffer);
			return (-1); }
		_exitt(buffer);
		av = _strtok(buffer), d = opendir(av[0]);
		if (d)
		{	_print_error(argv[0], cont, av[0]), cont++, _free(av);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
			closedir(d);
			continue; }
		if (!av)
		{	write(STDOUT_FILENO, "$ ", 2);
			continue; }
		_print_env(av[0], env);
		if (access(av[0], X_OK) == 0 && !opendir(av[0]))
			_execve(av), cont++;
		else if (av)
		{	i = _strlen(av[0]), av_0 = malloc(sizeof(char) * (i + 1));
			_getav0(&l_av, av, av_0);
			for (j = 0; env[j] && access(av[0], X_OK) != 0 && p_find == 0; j++)
				_path(av, env[j], av_0, l_av, &p_find);
			if (access(av[0], X_OK) == 0)
				_execve(av), cont++, flag_1 = 1, free(av_0); }
		if (flag_1 == 0 && p_find)
		{	_print_error(argv[0], cont, av[0]), cont++, free(av_0), _free(av);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2); } }
	free(buffer);
	return (-1); }
