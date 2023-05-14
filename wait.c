#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/**
 * wait - testing the wait fxn
 * Return: 0 for success and 1 for failing
 */
int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error\n");
		return (1);
	}
	if (child_pid == 0)
	{
		printf("Wait for me\n");
		sleep(5);
	}
	else
	{
		wait(&status);
		printf("I Already waited So you are done my boyyy\n");
	}
	return (0);
}
