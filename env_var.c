#include "main.h"
/**
 * my_getenv - custom getenv
 * @name: name to get the environment
 * Return: NULL
 */
char *my_getenv(const char *name)
{
	int i;
	int j;
	char *current_var;

	for (i = 0; environ[i] != NULL; i++)
	{
		current_var = environ[i];
		j = 0;
		while (name[j] != '\0' && name[j] == current_var[j])
		{
			j++;
		}
		if (name[j] == '\0' && current_var[j] == '=')
		{
			return (current_var + j + 1);
		}
}
	return (NULL);
}
