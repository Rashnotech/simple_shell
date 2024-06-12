#include "shell.h"

/**
 * free_command - frees all the commands in a single input
 * @command: the commands to be freed
 * @shell: shell info
 * Return: void
 */

void free_command(shell_t *shell, char ***command)
{
	char ***temp_c = command, **argv;
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

	free(command);
}
