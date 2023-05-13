#include <string.h>
#include <stdio.h>
/**
 * strtok - splits a string and returns an array of each word of the string
 * Return: 0
 */
int main(int ac, char **av)
{
	char *delim = " ";
	char *token;
	int i;

	for (i = 0; i <= ac - 1; i++)
	{
		token = strtok(av[i], delim);
		while (token != NULL)
		{
			printf("%s\n", token);
			
			token = strtok(NULL, delim);
		}
	}
		return (0);
}
