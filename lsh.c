#include "holberton.h"
/**
 * main - Receive the input commands
 * @argc: Integer to count inputs
 * @argv: Double char pointer
 *
 * Description: Receive the input commands
 * and pass them to executes orders
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int a;

	(void) argc;
	signal(SIGINT, _signalc);
	a = _prompt(argv);
	if (a == -1)
		kill(0, SIGTERM);
	return (0);
}
