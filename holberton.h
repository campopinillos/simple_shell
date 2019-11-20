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
#include <sys/stat.h>
#include <fcntl.h>

void _signalc(int sig_num);
ssize_t _prompt(char **argv, int *flag);
char **_strtok(char *str);
void fill(char *str, char *p);
int _execve(char **av);

#endif
