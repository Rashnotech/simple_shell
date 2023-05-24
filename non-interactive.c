#include "shell.h"

/**
 * non_interactive - non interactive mood
 */

void non_interactive(char *name, int argc)
{
	ssize_t no_char = 0;
	char *input = NULL, **argv, *token;
	size_t n;
	int errorcode;

	no_char = _getline(&input, &n, STDIN_FILENO);


	token = _strtok(input, "\n");
	while (token != NULL)
	{
		tokenizer(token, &argv, no_char);
		token = _strtok(NULL, "\n");
		if (argv[0] == NULL)
			continue;
		if (in_built(name, argv, input, argc) == 0)
			continue;
		errorcode = command_execute(argv, name);
		free_arrays(&argv);
	}
	free(input);
	exit(errorcode);
}
