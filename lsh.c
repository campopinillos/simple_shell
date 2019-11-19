#include "holberton.h"

int main(int argc, char **argv)
{
	signal(SIGINT, _signalc);
	int a = _prompt(argv);
	if(a == -1)
		kill(0, SIGTERM);
	return (0);
}
