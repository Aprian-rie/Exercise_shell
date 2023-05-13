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
	if (!buffer)
		return (-1);
	while ((c = fgetc(stream)) != EOF)
	{
		if (char_num >= bufsize - 1)
		{
			bufsize += 256;
			*lineptr = (char *)realloc(bufsize);

			if (!lineptr)
				return (-1);
		}
		(*lineptr)[pos++] = (char)c;

		if (c == "\n")
		{
			(*lineptr)[pos++] = '\0';
			return (pos);
		}

	}
	(*lineptr)[pos] = '\0';
	if (pos)
		return (pos);
	else
		return (-1);
}
