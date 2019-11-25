#include "holberton.h"
/**
 * _prompt - Executes orders
 * @argv: Double char pointer
 * @flag: Set interactive mode
 * Description: Executes orders
 * Return: 1 if succes and -1 if fails
 */
ssize_t _prompt(char **argv, int *flag, char **env)
{
	char *buffer, **av, *av_0;
	size_t s_buffer = 1;
	ssize_t lenght;
	int cont = 1, i = 0, j = 0, l_av = 0, flag_1 = 0, p_find = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2), *flag = 0;
	buffer = malloc(sizeof(char) * s_buffer);
	if (!buffer)
		return (0);
	while ((lenght = getline(&buffer, &s_buffer, stdin)) != -1)
	{
		p_find = 0, flag_1 = 0;
		if (lenght == EOF)
		{
			free(buffer);
			return (-1); }
		av = _strtok(buffer);
		if (!av)
		{
			write(STDOUT_FILENO, "$ ", 2);
			continue;
		}
		_exitt(av[0]);
		_print_env(av[0], env);
		if (access(av[0], X_OK) == 0)
			_execve(av), cont++;
		else if (av)
		{
			while (av[0][i] != '\0')
				i++;
			av_0 = malloc(sizeof(char) * (i + 1));
			_getav0(&l_av, av, av_0);
			j = 0;
			while(env[j] && access(av[0], X_OK) != 0 && p_find == 0)
				_path(av, env[j++], av_0, l_av, &p_find);
			if (access(av[0], X_OK) == 0)
				_execve(av), cont++, flag_1 = 1, free(av_0); 
		}
		if(flag_1 == 0 && p_find)
		{
			printf("%s: %i: %s: not found\n", argv[0], cont, av_0);
			cont++;
			i = 0;
			free(av_0);
			while (av[i])
				free(av[i++]);
			free(av);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
		}
	}
	free(buffer);
	return (-1);
}
