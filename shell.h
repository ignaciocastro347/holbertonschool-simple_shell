#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define  _GNU_SOURCE

extern char **environ;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _putchar(char);
char **split(char *, char *);
int count_tokens(char *, char*);
int free_string_list(char **);
char *_get_env(char *str);
char *_which(char *path, char *cmd);
void print_new_line(int *);
int execute_program(char **);
int print_not_found(char *);
#endif
