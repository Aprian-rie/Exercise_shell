#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
extern char **environ;
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int my_execvp(const char *file, char *const argv[]);
int _strlen(char *s);
#endif
