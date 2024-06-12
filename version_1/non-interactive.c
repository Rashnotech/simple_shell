#include "shell.h"

/**
 * non_interactive - non interactive mood
 * @argc: argument co nt
 * @name: nameif proht
 * Return: void
 */

void non_interactive(char *name, int argc)
{
	ssize_t no_char = 0;
	char *input = NULL, **argv, *token, *delim;
	size_t n;
	int errorcode = 0;

	no_char = _getline(&input, &n, STDIN_FILENO);
	delim = _strchr(input, ';') != NULL ? ";" : _strstr(input, "&&")
		!= NULL || _strstr(input, "||") != NULL ? "||&&" : NULL;
	if (delim)
		errorcode = handle_operators(input, name, no_char, argc, delim, errorcode);
	else
	{
		token = _strtok(input, "\n");
		while (token != NULL)
		{
			tokenizer(token, &argv, no_char);
			token = _strtok(NULL, "\n");
			if (argv[0] == NULL)
				continue;
			errorcode = in_built(name, argv, input, argc, errorcode);
			if (errorcode == 0)
				continue;
			else if (errorcode == 2)
				continue;
			errorcode = command_execute(argv, name);
			free_arrays(&argv);
		}
		free(input);
	}
	if (errorcode != 127 && errorcode != 0)
		errorcode = 2;
	exit(errorcode);
}
