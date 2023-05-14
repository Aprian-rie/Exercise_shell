#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
/**
 * calling multiple forks
 */
int main(void)
{
	pid_t child1;
	pid_t child2;

	child1 = fork();
	child2 = fork();

	if (child1 == 0)
	{
		if (child2 == 0)
		{
			printf("I am the child of process y\n");
		}
		else
		{
			printf("I am the child of process x\n");
		}
	}
	else 
	{
		if (child2 == 0)
		{
			printf("I am the child of process z\n");
		}
		else
		{
			printf("I am the parent process\n");
		}
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
		printf("Waited for child to finish\n");
	}
	return (0);
}
	
