#include "shell.h"

/**
 * freearray - frees array of strings
 * @av: array of strings to be freed
 * Return: void
 */

void freearray(char **av)
{

	for (; *av != NULL; av++)
		free(*av);
	free(av);
}
