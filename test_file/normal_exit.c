#include "shell.h"

/**
 * normal_exit - exits the shell.
 * @errorcode: checks error
 * Return: void
 */

void normal_exit(int errorcode)
{
	if (errorcode == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);                
}
