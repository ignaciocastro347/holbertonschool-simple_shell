#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define  _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **split(char *, char *);

#endif
