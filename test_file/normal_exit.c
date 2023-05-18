#include "shell.h"

/**
 * normal_exit - exits the shell.
 * @errorcode: checks error
 * Return: void
 */

void normal_exit(int errorcode)
{
	char **env = environ;
	char **next_var;

	while (*env != NULL)
	{
		next_var = env;
		++next_var;
		if (*next_var - *environ < 0)
			free(*next_var);
		env++;
	}
	if (errorcode == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);                
}
