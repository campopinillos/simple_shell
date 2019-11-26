#include "holberton.h"
/**
 * _signalc - Avoid exit with Ctrl C
 * @sig_num: Signal number
 *
 * Description: Avoid exit with Ctrl C
 * Return: Nothing
 */
void _signalc(int sig_num)
{
	(void) sig_num;
	write(STDOUT_FILENO, "\n$ ", 3);
}
