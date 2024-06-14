#include "shell.h"

/**
 * initialize - initialize the shell
 * @shell: shell info
 * @argc: argument count
 * @av: argument
 */

void initialize(shell_t *shell, int argc, char **av)
{
	shell->argc = argc;
	shell->argv = av;
	shell->error_code = 0;
	shell->fd = STDIN_FILENO;
	shell->is_interactive = isatty(STDIN_FILENO) ? 1 : 0;
	if (argc > 1)
	{
		shell->file = av[1];
		shell->fd = open(shell->file, O_RDONLY);
	}

}

