#include "main.h"
char *_strtok(char *str, const char *delim)
{
	static char *last_str = NULL;
	char *tok = NULL;

	if (str != NULL)
	{
		last_str = str;
	}
	else
	{
		if (last_str == NULL)
		{
			return (NULL);
		}
		str = last_str;
	}
	tok = _strpbrk(str, delim);
	if (tok == NULL)
	{
		last_str = NULL;
		return (str);
	}
	*tok = '\0';
	last_str = tok + 1;
	return (str);
}
