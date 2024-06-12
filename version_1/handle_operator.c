#include "shell.h"

/**
 * handle_operators - Handles command operator
 * @input: entry command
 * @name: programme name
 * @no_char: number of characters
 * @argc: argument counter
 * @delim: delimeters
 * @code: status error code
 * Return: an integer value of 0 otherwise -1
 */
int handle_operators(char *input, char *name, ssize_t no_char,
		int argc, char *delim, int code)
{
	char **argv = NULL, *token, *input_copy = NULL;
	int ret, opand = 0, opor = 0;

	argc = 2;
	input_copy = my_strdup(input);
	opand = _strstr(input, "&&") != NULL ? 1 : 0;
	opor = _strstr(input, "||") != NULL ? 2 : 0;
	token = _strtok(input_copy, delim);
	while (token != NULL)
	{
		tokenizer(token, &argv, no_char);
		token = _strtok(NULL, delim);
		if (argv[0] == NULL)
		{
			free(argv);
			free(input_copy);
			continue;
		}
		if (my_strcmp(argv[0], "exit") == 0)
			free(input_copy);
		if (in_built(name, argv, input, argc, code) == 0)
			continue;
		ret = command_execute(argv, name);
		if (opand && opor)
		{
			if ((ret != 0 && my_strcmp(token, "||") == 0)
					|| (ret == 0 && my_strcmp(token, "&&") == 0))
				continue;
		}
		else
		{
			if ((ret != 0 && opand == 1)
				|| (ret == 0 && opor == 2))
				break;
		}
		free_arrays(&argv);
	}
	free(input_copy);
	free(input);
	return (ret);
}
