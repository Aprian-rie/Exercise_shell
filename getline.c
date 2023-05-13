#include <stdio.h>
/**
 * getline - my custom getline function
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t _read;

	printf("$: ");
	_read = getline(&buffer, &bufsize, stdin);
	if (_read == -1)
		printf("Error reading the line");
	printf("%s", buffer);
	return (0);
}
