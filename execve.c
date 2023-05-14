#include <stdio.h>
#include <unistd.h>
/**
 * execve -  executes another program
 * Return: Another program
 */
int main(void)
{
	char *pathname = "/usr/bin/ls";
	char *argv[] = {"ls", "-l"};
	char *const envp[] = {NULL};

	printf("Start of execve command");
	printf("--------------------------");
	if ((execve(pathname, argv, envp)) == -1)
	{
		perror("could not execute execve command");
	}
	printf("Something went wrong");
	return (0);
}
