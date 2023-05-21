#include "shell.h"

/**
 * my_strlen - return the length of the given string
 * @s: char to be checked
 * Return: 0 is success
 */
int my_strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);
	for (; *s++;)
		i++;

	return (i);
}


/**
 * my_strdup - for duplicating strings
 * @str: the string to be duplicated.
 * Return: the dublicate of str on success and NULL on failure
 */

char *my_strdup(const char *str)
{
	char *dup_str;
	size_t stringlen;

	stringlen = my_strlen(str) + 1;
	dup_str = malloc(stringlen * sizeof(char));

	if (dup_str != NULL)
		my_memcpy(dup_str, str, stringlen);

	return (dup_str);
}




/**
 * my_memcpy - for copieing n bytes from memory area src
 * to memory dest
 * @n: number of bytes to be copied.
 * @src: bytes from memory area
 * @dest: to memory area
 * Return: a pointer to @dest
 */

char *my_memcpy(char *dest, const char *src, unsigned int n)
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
 * my_strcmp -this function compares two strings.
 * @str1: the first to be string
 * @str2: second string.
 * Return: 0 on success 1 on failure
 */

int my_strcmp(const char *str1, const char *str2)
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
 * my_strcat - to concatenate two strings.
 * @dest: char to be concanetated to
 * @src: string
 * Return: dest
 */

char *my_strcat(char *dest, char *src)
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
