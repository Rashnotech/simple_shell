#include "shell.h"

/**
 * free_command - frees all the commands in a single input
 * @shell: shell info
 *
 * Return: void
 */

void free_command(shell_t *shell)
{
	char ***temp_c = shell->commands, **argv;
	int j;

	(void) shell;
	if (temp_c == NULL)
		return;

	for (; *temp_c != NULL; temp_c++)
	{
		argv = *temp_c;
		for (j = 0; argv[j] != NULL; j++)
			free(argv[j]);
		free(argv);
	}

	free(shell->commands);
}
