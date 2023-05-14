#include <string.h>
#include <stdio.h>
/**
 * _strtok - tokenizes the string
 * Return 0 on success
 */
int main(int ac, char **av)
{
	char *token;
	char *delim = " ";
	(void) ac;

	token = strtok(av[1], delim);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
