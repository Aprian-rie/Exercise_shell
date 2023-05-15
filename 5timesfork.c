#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * executing fork 5 times
 */
int main(void)
{
	pid_t child1, child2, child3, child4;

	child1 = fork();
	if (child1 != 0)
	{
		child2 = fork();
		if (child2 != 0)
		{
			child3 = fork();
			if (child3 != 0)
			{
				child4 = fork();
			}
		}
	}
	if (child1 == 0)
	{
		printf("First child\n");
		if (child2 == 0)
		{
			printf("Second Child\n");
			if (child3 == 0)
			{
				printf("Third Child\n");
				if (child4 == 0)
				{
					printf("Fourth Child\n");
				}
			}
		}
	}
	if (child1 != 0 && child2 != 0 && child3 !=0 && child4 != 0)
	{
		printf("Parent :)\n");
	}
	return (0);
}
