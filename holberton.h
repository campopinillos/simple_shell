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
ssize_t _prompt(char **argv, int *flag, char **env);
char **_strtok(char *str);
void fill(char *str, char *p);
int _execve(char **av);
int _exitt(char *av);
void _path(char **av, char *env, char *av_0, int av_l, int *p_find);
void *_realloc(void *ptr, int old_size, int new_size);
int _find_X(int c_path, char *env, char *av_0, int l_av, int start, char **path);
char * _getav0(int *l_av, char **av);

#endif
