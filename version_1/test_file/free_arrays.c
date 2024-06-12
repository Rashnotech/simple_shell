#include "shell.h"

/**
 * free_arrays - for freeing array of strings
 * @av: the array of strings to be freed
 * Return: void
 */

void free_arrays(char ***av)
{
	char **tempav = *av;

	if (tempav == NULL)
		return;


	for (; *tempav != NULL; tempav++)
	{
		free(*tempav);
		*tempav = NULL;
	}

	free(*av);
	*av = NULL;
}
