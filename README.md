![Holberton school logo](https://secure.meetupstatic.com/photos/event/b/c/5/6/highres_475548214.jpeg)
# Simple Shell Project

This is collaborative project made by Luz Adriana Ariza and Campo Elias Pinillos, students of Software Engineering at Holberton School. This repository contains the files for Holberton's **simple_shell project**. It consists of developing and making our own UNIX command interpreter (Shell).

 It's a recreation of the <kbd>sh</kbd> shell a command line interpreter, this program has the exact same output as <kbd>sh</kbd> <kbd>(/bin/sh)</kbd> as well as the exact same error output.


## Repo Contents:

These are the files with the custom funtions and system calls, each one contains a brief description:

|   ***File***    |  **Decription**                     |
|---------------|---------------------------------------|
|  `holberton.h`	|  Header file with the prototypes	|
|  `lsh.c.c` |  Main File functions to execute |
|  `_prompt.c` |  Prompt and getline file	|
|  `_execve.c`	|  Execute function |
|  `_strtok.c`  | Custom strtok function  |
|  `_signal.c`  | Ctrl + C deal function	|
|  `path.c`  | Functions for handling the PATH  |

### List of allowed functions and system calls:

This files only contains the following allowed funtion and system calls:

| ***System call*** | ***Man page*** | ***System call*** | ***Man page*** |
| ------------- | ------------- | ------------- | ------------- |
| access  | man 2 access  | open |  man 2 open |
| chdir  | man 2 chdir | opendir |  man 3 opendir |
| close  | man 2 close | perror |  man 3 perror |
| closedir  | man 3 closedir  | read |  man 2 read |
| execve  | man 2 execve  | readdir |  man 3 readdir |
| exit  | man 3 exit  | signal |  man 2 signal |
| _exit  | man 2 _exit  | stat |  __xstat) |  man 2 stat |
| fflush  | man 3 fflush | lstat |  __lxstat) |  man 2 lstat |
| fork  | man 2 fork  | fstat |  __fxstat) |  man 2 fstat |
| free  | man 3 free  | strtok |  man 3 strtok |
| getcwd  | man 3 getcwd | wait |  man 2 wait |
| getline  | man 3 getline | waitpid |  man 2 waitpid |
| isatty  | man 3 isatty  | wait3 |  man 2 wait3 |
| kill  | man 2 kill  | wait4 |  man 2 wait4 |
| malloc | man 3 malloc | write |  man 2 write |


## Quick Start

1. Clone repo
```
git clone https://github.com/campopinillos/simple_shell.git
```
2. Change directory to simple_shell
```
cd simple_shell/
```
3. Compile all the `.c` files in /simple_shell
```
gcc -Wall -Werror -Wextra -pedantic *.c -o lsh
```

### Interactive Mode
In interactive mode input is accepted from character input, as follow:
```
$ ./lsh
$ /bin/ls -l
total 52
-rw-r--r-- 1 vagrant vagrant   168 Nov 20 01:50 AUTHORS
-rw-r--r-- 1 vagrant vagrant  2789 Nov 20 03:47 README.md
-rw-r--r-- 1 vagrant vagrant   486 Nov 20 00:50 _execve.c
-rw-r--r-- 1 vagrant vagrant   763 Nov 20 01:45 _prompt.c
-rw-r--r-- 1 vagrant vagrant   239 Nov 19 14:35 _signal.c
-rw-r--r-- 1 vagrant vagrant  1039 Nov 19 14:38 _strtok.c
-rwxr-xr-x 1 vagrant vagrant 18278 Nov 20 01:46 a.out
-rw-r--r-- 1 vagrant vagrant   394 Nov 19 21:37 holberton.h
-rw-r--r-- 1 vagrant vagrant   443 Nov 20 00:55 lsh.c
-rw-r--r-- 1 vagrant vagrant     0 Nov 20 01:31 man_1_simple_shell
```

### Non-Interactive Mode
In non-interactive mode, the shell is run from commands being piped in. The subshell
is only opened as the command is carried out and closes at the completion of the command.

```
> echo "/bin/ls -l"  | ./lsh
total 52
-rw-r--r-- 1 vagrant vagrant   168 Nov 20 01:50 AUTHORS
-rw-r--r-- 1 vagrant vagrant  2789 Nov 20 03:47 README.md
-rw-r--r-- 1 vagrant vagrant   486 Nov 20 00:50 _execve.c
-rw-r--r-- 1 vagrant vagrant   763 Nov 20 01:45 _prompt.c
-rw-r--r-- 1 vagrant vagrant   239 Nov 19 14:35 _signal.c
-rw-r--r-- 1 vagrant vagrant  1039 Nov 19 14:38 _strtok.c
-rwxr-xr-x 1 vagrant vagrant 18278 Nov 20 01:46 a.out
-rw-r--r-- 1 vagrant vagrant   394 Nov 19 21:37 holberton.h
-rw-r--r-- 1 vagrant vagrant   443 Nov 20 00:55 lsh.c
-rw-r--r-- 1 vagrant vagrant     0 Nov 20 01:31 man_1_simple_shell
```

### Man page

For further information please refer to the man page - accessed in terminal with:
```
> man ./man_1_simple_shell
```

### Examples

Some other examples to execute commands in the ./lsh interactive mode:
```
~/simple_shel > ./lsh
```
**ls**:

```
$ ls
AUTHORS    _prompt.c  a.out	   man_1_simple_shell README.md  _signal.c  holberton.h _execve.c  _strtok.c  lsh.c
```
**pwd**:
```
$ pwd
/home/vagrant/simple_shell
```

## Authors
* **Luz Adriana Ariza** - [AdrianaAriza](https://github.com/AdrianaAriza) - [@Adriana92060737](https://twitter.com/Adriana92060737)

* **Campo Elias Pinillos** - [campopinillos](https://github.com/campopinillos) - [@campopinillos](https://twitter.com/CampoPinillos)
