#include "shell.h"

/**
 * get_environ_var - get the enironment varieble
 * Return: void
 */

void get_environ_var(void)
{
	unsigned int len, i = 0;

	while (environ[i] != NULL)
	{
		len = _strlen(environ[i]);

		write(1, environ[i], len);
		if (environ[++i] != NULL)
			write(1, "\n", 1);
	}
}
