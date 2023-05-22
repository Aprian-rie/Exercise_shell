#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
extern char **environ;
/**
 * A super simple shell
 * run commands with their full path
 * without any arguments
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *line = NULL;
	char *tokens, **toks;
	size_t len = 0;
	int count;
        int status;
	pid_t child1;
	ssize_t _read;
	int bufsize;
	const char *delim = " \n";

	while (1)
	{
		write(STDOUT_FILENO, "$: ", 4);
		/* Reads the user input*/
		_read = getline(&line, &len, stdin);
		if (_read == -1)
		{
			perror("Error reading input");
			exit(1);
		}
		(line)[_read - 1] = '\0';
		/* tokenizes the input */
		count = 0;
		bufsize = 64;
		toks = malloc(bufsize * sizeof(char *));
		tokens = strtok(line, delim);
		while (tokens != NULL)
		{
			toks[count] = tokens;
			count++;
			tokens = strtok(NULL, delim);
		}
		toks[count] = NULL;
		/**Executing commands in the child process */
		child1 = fork();
		if (child1 == -1)
		{
			perror("Failed to fork");
			exit(1);
		}
		else if (child1 == 0)
		{
			if (my_execvp(toks[0], toks) == -1)
			{
				perror("Failed to execute execve");
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		free(toks);
	}
	free(line);
	return (0);
}
