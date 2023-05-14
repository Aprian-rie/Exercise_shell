#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * process ID's from code vault
 */
int main(void)
{
	int id = fork();
	int res;

	if (id == 0)
	{
		sleep(1);
	}
	printf("Current Id: %d and parent ID:%d \n", getpid(), getppid());
	res = wait(NULL);
	if (res == -1)
	{
		printf("No process to wait for\n");
	}
	else
	{
		printf("%d finished execution\n", res);
	}
	return (0);
}
