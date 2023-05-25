#include "shell.h"

/**
 * normal_exit - exits the shell.
 * @errorcode: checks error
 * Return: void
 */
void normal_exit(int errorcode)
{
	(void)errorcode;
	if (errorcode)
		exit(2);
	else
		exit(0);
}
