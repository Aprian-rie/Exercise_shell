#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
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
	pid_t child1;
	pid_t child2;
	int status;

	child1 = fork();
	child2 = fork();
	if (child1 != 0 || child2 != 0)
	{
		wait(&status);
		printf("Child 1 is done\n");
	}
	if (child2 != 0)
	{
		wait(&status);
		printf("Child 2 is done\n");
	}
	if ((execve(pathname, argv, environ)) == -1)
	{
		perror("Error: ");
		return (1);
	}
	return (0);
}
