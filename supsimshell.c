#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
extern char **environ;
/**
 * A super simple shell
 * run commands with their full path
 * without any arguments
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t _read;
	char *cmd;
	char *args[] = { NULL };
	pid_t child1;
	int status;

	while (1)
	{
		printf("$: ");
		_read = getline(&line, &len, stdin);
		
		if (_read == -1)
		{
			printf("Error reading input\n");
			exit(1);
		}
		line[_read-1] = '\0';
		cmd = line;
		child1 = fork();
		if (child1 == -1)
		{
			printf("failed to fork the process\n");
			continue;
		}
		else if (child1 == 0)
		{
			if (execve(cmd, args, NULL) == -1)
			{
				printf("Failed to execute execve\n");
			}
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
