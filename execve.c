#include <stdio.h>
#include <unistd.h>
extern char **environ;
/**
 * execve -  executes another program
 * Return: Another program
 */
int main(void)
{
	char *pathname = "/bin/ls";
	char *argv[] = {"ls", "-l"};

	printf("Start of execve command\n");
	printf("--------------------------\n");
	if ((execve(pathname, argv, environ)) == -1)
	{
		perror("could not execute execve command\n");
	}
	printf("Something went wrong\n");
	return (0);
}
