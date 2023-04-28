#include "shell.h"

/**
 * freearray - frees array of strings
 * @av: array of strings to be freed
 * Return: void
 */

void freearray(char ***av)
{
	char **temp = *av;

	if (temp == NULL)
		return;


	for (; *temp != NULL; temp++)
	{
		free(*temp);
		*temp = NULL;
	}
	free(*av);
	*av = NULL;
}
