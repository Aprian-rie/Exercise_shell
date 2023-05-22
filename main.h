#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
extern char **environ;
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int my_execvp(const char *file, char *const argv[]);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, const char *s2);
char *my_getenv(const char *name);
#endif

