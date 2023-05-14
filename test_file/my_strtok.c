#include <stdio.h>

/**
 * _strtok - for tokenizing string into smmall token
 * @str: the string to be tokenized
 * @delim: delumiters to seperate strings
 * Return: a pointer to the beginig of string
 */

char *_strtok(char *str, const char *delim)
{
	static char *str_copy;
	char *token;
	const char *delim_copy;

	if (str != NULL)
		str_copy = str;
	if (str_copy == NULL)
		return (NULL);

	token = str_copy;

	for (; *str_copy != '\0'; str_copy++)
	{
		delim_copy = delim;
		for (; *delim_copy != '\0'; delim_copy++)
		{
			if (*str_copy == *delim_copy)
			{
				*str_copy = '\0';
				str_copy++;
				if (*token != '\0')
					return (token);

				else
				{
					token = str_copy;
					break;
				}
			}
		}
	}
	str_copy = NULL;
	if (*token == '\0')
		return (NULL);
	else
		return (token);
}
