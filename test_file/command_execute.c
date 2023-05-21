#include "shell.h"

/**
 * command_execute - for executing commands
 * @argv: array of strings
 * @name: the progamme name
 * Return: 0 on success and 1 on failure
 */

int command_execute(char **argv, char *name)
{
	char *full_path, **next_args;
	int status, ret = 0;
	pid_t my_pid;

	(void)ret;
	full_path = my_getpath(argv[0]);
	if (full_path != NULL)
	{
		if (my_strcmp(full_path, argv[0]) != 0)
		{
			free(argv[0]);
			argv[0] = full_path;
		}
	}
	else
	{
		handle_error(name, argv[0]);
		return (1);
	}
	my_pid = fork();
	if (my_pid == -1)
		perror("Error: ");
	else if (my_pid == 0)
		execve(argv[0], argv, environ);
	else
	{
		waitpid(my_pid, &status, 0);
		if (status == 0)
		{
			next_args = argv;
			while (*next_args != NULL)
			{
				if (my_strcmp(*next_args, "&&") == 0)
				{
					next_args++;
					break;
				}
				next_args++;
			}
			if (*next_args != NULL)
				ret = command_execute(next_args, name);
		}
	}
	return (0);
}
