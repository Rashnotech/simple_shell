#include "shell.h"

/**
 * check_input - check if input should be processed or not
 * @shell: info about tje current shell
 * @no_char: number of characters read from input
 * @input: The input string
 * Return: 1 if shell should continue without
 * processing the input, -1 if shell should end
 * 0 if shell should process input
 */

int check_input(shell_t *shell, size_t no_char, char *input)
{
	if (no_char == (size_t) -1)
	{
		free(input);
		if (shell->is_interactive)
			my_putchar('\n');
		return (-1);
	}
	if (no_char == (size_t) 1)
	{
		free(input);
		if (!shell->is_interactive)
			return (-1);
		return (1);
	}
	return (0);
}
