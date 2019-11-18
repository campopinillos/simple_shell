#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
char **strtow(char *str);
void _execve(char **av, char *argv);
#endif
