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
	(void) argc;
	signal(SIGINT, _signalc);
	if (_prompt(argv) == -1)
	{
		printf("\n");
		exit(0);
	}
	return (0);
}
