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
/**
 * _strcmp - compares two strings
 * @s1: 1st parameter to be compared
 * @s2: 2nd parameter to be compared
 * Return: +ve or -ve
 */
int _strcmp(char *s1, const char *s2)
{
	unsigned char c1, c2;

	do	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0')
			return (c1 - c2);
	} while (c1 == c2);
	return (c1 - c2);
}
