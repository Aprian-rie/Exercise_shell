#include "main.h"
/**
 * _strlen - finds the length of the string
 * @s: String character for length
 * Return: String length
 */
int _strlen(const char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * *_strcpy - copies the string from src to dest
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;
	int i;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _strcat - cncatenates 2 strings
 * @dest: final value
 * @src: One being appended to
 * Return: Concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	for (i = 0; *(dest + i) != '\0'; i++)
	{
	}
	for (j = 0; *(src + j) != '\0'; j++)
	{
		*(dest + i) = *(src + j);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
