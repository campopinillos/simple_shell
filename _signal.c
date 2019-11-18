#include "holberton.h"

void _signalc(int sig_num)
{ 
	write(STDOUT_FILENO,"\n$ ",3);
}
