#include "shell.h"


/**
 * my_strtok - a custom string tokeniser
 * @str: sting to be tokenized
 * @delim: delimeter
 * Return: a string
 */

char *my_strtok(char *str, const char *delim)
{
	static char *str_copy;
	char *token;
	const char *delim_copy = delim;

	if (str != NULL)
		str_copy = str;
	if (str_copy == NULL)
		return (NULL);

	str_copy += my_strspn(str_copy, delim_copy);

	if (*str_copy == '\0')
		return (NULL);

	token = str_copy;

	str_copy += my_strcspn(str_copy, delim_copy);

	if (*str_copy != '\0')
	{
		*str_copy = '\0';
		str_copy++;
	}

	return (token);
}

/**
 * my_strspn - removes delimeter chars from beginig
 * @str: string
 * @delim: the delimeter
 * Return: the index of the first char in the str
 */
size_t my_strspn(char *str, const char *delim)
{
	size_t len = 0, delim_index;

	for (; str[len] != '\0'; len++)
	{
		delim_index = 0;

		for (; delim[delim_index] != '\0'; delim_index++)
		{
			if (str[len] == delim[delim_index])
				break;
		}

		if (delim[delim_index] == '\0')
			return (len);
	}
	return (len);
}



/**
 * my_strcspn - removes delimeter chars from beginig
 * @str: string
 * @delim: the delimeter
 * Return: the index of the first char in the str
 */

size_t my_strcspn(char *str, const char *delim)
{
	size_t len, index;

	for (len = 0; str[len] != '\0'; len++)
	{
		for (index = 0; delim[index] != '\0'; index++)
		{
			if (str[len] == delim[index])
				return (len);
		}
	}

	return (len);
}

/**
 * _strtok - a custom string tokeniser
 * @str: sting to be tokenized
 * @delim: delimeter
 * Return: a string
 */
char *_strtok(char *str, const char *delim)
{
	static char *str_copy;
	char *token;

	if (str != NULL)
		str_copy = str;
	if (str_copy == NULL)
		return (NULL);

	str_copy += my_strspn(str_copy, delim);

	if (*str_copy == '\0')
		return (NULL);

	token = str_copy;

	str_copy += my_strcspn(str_copy, delim);

	if (*str_copy != '\0')
	{
		*str_copy = '\0';
		str_copy++;
	}
	return (token);
}
