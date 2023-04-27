#include "shell.h"

/**
 * execute - for executing commands
 * @argv: array of commands and their arguments
 * @name: the name of the progamme
 */

int execute(char **argv, char *name)
{
	char *fullpath;
	int status = 0;
	pid_t my_pid;



	fullpath = getpath(argv[0]);
	if (fullpath != NULL)
	{
		if (_strcmp(fullpath, argv[0]) != 0)
		{
			free(argv[0]);
			argv[0] = fullpath;
		}
	}
	else
	{
		_puterror(name, argv[0]);
		write(2, "1", 1);
		return (1);
	}
	my_pid = fork();
	if (my_pid == -1)
		perror("Error: ");
	else if (my_pid == 0)
	{
		execve(argv[0], argv, environ);

	}
	else
		waitpid(my_pid, &status, 0);
	return (0);
}
