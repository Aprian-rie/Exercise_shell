#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
extern char **environ;
/**
 * main - executes ls -l /tmp 5 times in 
 * 5 different child processes
 * Return: 0 on success
 */
int main(void)
{
	char *pathname = "/bin/ls";
	char *argv[] = {"ls", "-l", "/tmp", NULL};
	pid_t children;
	int status, i;

	for (i = 0; i < 5; i++)
	{
		children = fork();
		if (children == 0)
		{
			execve(pathname, argv, environ);
			perror("execve");
			exit (1);
		}
		else if (children < 0)
		{
			perror("fork");
			exit (1);
		}
		else
		{
			wait (&status);
		}
		
	}
	return (0);
}
