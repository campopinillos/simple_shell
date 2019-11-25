#include "holberton.h"
/**
 * main - Receive the input commands
 * @argc: Integer to count inputs
 * @argv: Double char pointer
 * @environment: Double char pointer
 *
 * Description: Receive the input commands
 * and pass them to executes orders
 * Return: 0 if success
 */
int main(int argc, char **argv, char **env)
{
	int flag = 1;
	int *p = &flag;

	(void) argc;
	(void) environment;
	signal(SIGINT, _signalc);
	if (_prompt(argv, p, env) == -1)
	{
		if (flag == 0)
			printf("\n");
		exit(0);
	}
	return (0);
}
