#include "holberton.h"

int main(int argc, char **argv)
{
	(void) argc;
	signal(SIGINT, _signalc);
	_prompt(argv);
	return (0);
}
