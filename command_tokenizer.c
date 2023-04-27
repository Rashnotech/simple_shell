#include "shell.h"

/**
 * command_tokenizer - tokenizes strings
 * @command: the string to be tokenized
 * @argv: an array of strings
 * @num_chars: the number chars written
 * Return: An array of string
 */

char **command_tokenizer(char *command, char ***argv, ssize_t num_chars)
{
	char *commandcopy = NULL, *token;
	char *delim = " \"\n";
	int i, num_token = 0;

	commandcopy = malloc(sizeof(char) * (num_chars + 3));
	if (commandcopy == NULL)
	{
		exit(-1);
	}
	_strcpy(commandcopy, command);
	token = strtok(commandcopy, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	*argv = malloc(sizeof(char *) * num_token);
	if ((*argv) == NULL)
	{
		exit(-1);
	}
	token = strtok(command, delim);
	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy((*argv)[i], token);
		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;
	free(commandcopy);

	return (*argv);
}
