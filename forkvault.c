#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * tutorials from code vault
 */
int main(void)
{
	pid_t id = fork();
	int n;
	int i;
	int status;

	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if (id != 0)
		wait(&status);
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
	{
		printf("\n");
	}
	return (0);
}
