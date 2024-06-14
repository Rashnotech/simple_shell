#include "shell.h"

/**
 * command_execute - for executing commands
 * @argv: array of strings
 * @name: the progamme name
 * Return: 0 on success and 1 on failure
 */

int command_execute(char **argv, char *name)
{
	char *full_path;
	int status, err;
	pid_t my_pid;

	full_path = my_getpath(argv[0]);
	if (full_path == NULL)
		err = handle_error(name, argv[0]);
	else
	{
		my_pid = fork();
		if (my_pid == -1)
			perror("Error: ");
		else if (my_pid == 0)
			execve(full_path, argv, environ);
		else
			wait(&status);
		err = status;
	}
	free(full_path);
	return (err);
}
