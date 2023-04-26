#include "shell.h"

/**
 * _strcpy - copy the string pointed to by src to dest
 * @dest: char to check
 * @src: char to check
 * Return: 0 is success
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

/**
 * _strncmp - compaters two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the number of chsr to be compared
 * Return: 0
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}
	return (0);
}
