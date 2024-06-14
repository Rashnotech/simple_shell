#include "shell.h"

/**
 * command_execute - for executing commands
 * @shell: shell info
 * @argv: array of strings
 *
 * Return: 0 on success and 1 on failure
 */

void command_execute(shell_t *shell, char **argv)
{
	char *full_path;
	int status;
	pid_t my_pid;

	full_path = my_getpath(argv[0]);
	if (full_path == NULL)
		shell->error_code = handle_error(shell->argv[0], argv[0]);
	else
	{
		my_pid = fork();
		if (my_pid == -1)
			perror("Error: ");
		else if (my_pid == 0)
			execve(full_path, argv, environ);
		else
			wait(&status);
		shell->error_code = status;
	}
	if (access(argv[0], X_OK) == -1)
		free(full_path);
}
