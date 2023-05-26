#include "main.h"
#include <string.h>
#define BUFFER_SIZE 4096
/**
 * our_getline - custom getline function
 * @lineptr: line pointer
 * @n: no of bytes read
 * @FILE: where to read
 */
ssize_t our_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_size = 0;
	static size_t buffer_pos = 0;
	ssize_t line_length = 0;
	ssize_t line_length_new;
	size_t i, j;
	int newline_found;
	int fd;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	fd = fileno(stream);
	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_size <= 0)
			{
				break;
			}
		}
		i = buffer_pos;
		while (i < buffer_size && buffer[i] != '\n')
		{
			i++;
		}
		line_length_new = line_length + (i - buffer_pos);
		if ((size_t)(line_length_new + 1) > *n)
		{
			*n = (size_t)(line_length_new + 1);
			new_lineptr = (char *)realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			{
				perror("Memory allocation error");
				exit(1);
			}
			*lineptr = new_lineptr;
		}
		for (j = buffer_pos; j < i; j++)
		{
			(*lineptr)[line_length++] = buffer[j];
		}
		buffer_pos = i + 1;
		if (i < buffer_size && buffer[i] == '\n')
		{
			newline_found = 1;
			break;
		}
	}
	(*lineptr)[line_length] = '\0';
	return (newline_found || line_length > 0) ? line_length : -1;
}
