#include "main.h"
/**
 * my_getline - custom getline function
 * Return: no of chars read if success
 * and if failed it returns -1
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t char_num;
	size_t bufsize = 256;
	int c;

	*lineptr = (char *)malloc(bufsize);
	if (!lineptr)
		return (-1);
	while ((c = fgetc(stream)) != EOF)
	{
		if (char_num >= bufsize - 1)
		{
			break;

			if (!lineptr)
				return (-1);
		}
		(*lineptr)[char_num++] = (char)c;

		if (c == '\n')
		{
			(*lineptr)[char_num++] = '\0';
			return (char_num);
		}

	}
	(*lineptr)[char_num] = '\0';
	if (char_num)
		return (char_num);
	else
		return (-1);
}
