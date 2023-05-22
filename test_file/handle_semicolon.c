#include "shell.h"
<<<<<<< HEAD

/**
 * handle_semicolon - executes commands seperated by semicolon
 * @input: a line of commands seperated by ';'
 * @name: programe name
 * @no_char: the no of chars in input
 * @argc: argument count
 * Return: 0 on success
 */

int handle_semicolon(char *input, char *name, ssize_t no_char, int argc)
=======
/**
 * handle_semicolon - Handle semicolons in command
 * @input: entry command
 * @name: programme name
 * @no_char: number of characters
 * @argc: argument counter
 * @delim: delimeters
 * Return: an integer value of 0 otherwise -1
 */
int handle_semicolon(char *input, char *name, ssize_t no_char,
		int argc, char *delim)
>>>>>>> remotes/Rashnotech/bourne
{
	char **argv = NULL, *token, *input_copy;
	int ret;

	argc = 2;
	input_copy = my_strdup(input);
<<<<<<< HEAD
	token = _strtok(input_copy, ";");

	while (token != NULL)
	{
		tokenizer(token, &argv, no_char);
		token = _strtok(NULL, ";");
=======
	token = my_strtok(input_copy, delim);
	while (token != NULL)
	{
		tokenizer(token, &argv, no_char);
		token = my_strtok(NULL, delim);
>>>>>>> remotes/Rashnotech/bourne
		if (argv[0] == NULL)
			continue;
		if (in_built(name, argv, input, argc) == 0)
			continue;
		ret = command_execute(argv, name);
		if ((ret != 0 && my_strcmp(delim, "&&") == 0)
				|| (ret == 0 && my_strcmp(delim, "||") == 0))
			break;
		free_arrays(&argv);
	}
	free(input_copy);
	free(input);
	return (0);
}
