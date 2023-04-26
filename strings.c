#include "shell.h"

/**
 * _strlen - return the length of a string
 * @s: char to check
 * Description: this will return the length of a string
 * Return: 0 is success
 */

int _strlen(const char *s)
{
	int a = 0;

	for (; *s++;)
		a++;
	return (a);
}


/**
 * _strdup - to duplicate strings
 * @str: string to be duplicated
 * Return: the dublicated string on success or NULL on failure
 */

char *_strdup(const char *str)
{
	char *dup;
	size_t len;

	len = _strlen(str) + 1;
	dup = malloc(len * sizeof(char));

	if (dup != NULL)
		memcpy(dup, str, len);

	return (dup);
}




/**
 * _memcpy - function copies @n bytes from memory area @src
 * to memory area @dest
 * @n: function copies
 * @src: bytes from memory area
 * @dest: to memory area
 * Return: a pointer to @dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
/**
 * _strcmp - compares two strings
 * @str1: the first to be compared
 * @str2: the second string
 * Return: 0
 */

int _strcmp(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (1);
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((const unsigned char)*str1 - (const unsigned char)*str2);
}


/**
 * _strcat - concat 2 string
 * @dest:char
 * @src:char
 * Return:char
 */

char *_strcat(char *dest, char *src)
{

	if (dest == NULL)
	{
		return (NULL);
	}
	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}
