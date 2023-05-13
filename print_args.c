#include <stdio.h>
/**
 * print_args - prints all arguments without using ac
 * @argv:  argument vector
 * @ac: the argument count
 * Return: 0 for success
 */
int main(int ac, char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
