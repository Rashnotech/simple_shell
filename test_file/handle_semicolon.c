#include "shell.h"

/**
 * handle_semicolon - executes commands seperated by semicolon
 * @input: a line of commands seperated by ';'
 * @name: programe name
 * @no_char: the no of chars in input
 * @argc: argument count
 * Return: 0 on success
 */

int handle_semicolon(char *input, char *name, ssize_t no_char, int argc)
{
	char **argv = NULL, *token, *input_copy;

	argc = 2;
	input_copy = my_strdup(input);
	token = _strtok(input_copy, ";");

	while (token != NULL)
	{
		tokenizer(token, &argv, no_char);
		token = _strtok(NULL, ";");
		if (argv[0] == NULL)
			continue;
		if (in_built(name, argv, input, argc) == 0)
			continue;
		command_execute(argv, name);
		free_arrays(&argv);
	}
	free(input_copy);
	free(input);

	return (0);
}

