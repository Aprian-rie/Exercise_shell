#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
extern char *builtin_str[];
extern int (*builtin_func[])(char **);
extern int num_builtins();

int my_execvp(const char *file, char *const argv[]);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, const char *s2);
char *my_getenv(const char *name);
ssize_t our_getline(char **lineptr, size_t *n, FILE *stream);
int our_exit(char **toks);
int our_cd(char **toks);
char *_strtok(char *str, const char *delim);
char *_strpbrk(char *s, const char *accept);
#endif

