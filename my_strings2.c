#include "shell.h"
/**
 * my_strcpy - copy the string in src to dest
 * @dest: string to be copied to
 * @src: string to be copied from
 * Return: dest is success
 */
char *my_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

/**
 * my_strncmp - compares n char in strings
 * @s1: string 1
 * @s2: second string
 * @n: numbers of char to be copied
 * Return: 0 on succesd or 1 on failur
 */

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * _strstr - find the occurence needle in the haystack and print
 * @haystack: given string character
 * @needle: search substring
 *
 * Return: string of found character otherwise NULL
 */
char *_strstr(char *haystack, char *needle)
{
	char *stk, *stk_start, *stk2;
	int i = 0;

	stk = haystack;
	while (*stk != '\0')
	{
		stk_start = stk, stk2 = needle;
		while (stk[i] != '\0' && stk2[i] != '\0' && stk[i] == stk2[i])
			i++;
		if (stk[i] == '\0')
			return (stk_start);
		stk = stk_start + 1;
	}
	return (0);
}

/**
 * _strncpy - copy a (n) number of string
 * @dest: an operand to contain copied string
 * @src: an operand that hold string to be copied
 * @n: specify number of string to copy
 *
 * Return: copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
