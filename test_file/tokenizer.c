#include "shell.h"
/**
 * tokenizer - for tokenizing of strings
 * @command: string to be tokenized
 * @argv: an array of strings
 * @num_chars: the number chars written
 * Return: An array of string
 */

int tokenizer(char *command, char ***argv, ssize_t num_chars)
{
	char *command_copy = NULL, *token;
	char *delim = " \t\r\n;";
	int i, numOf_tokens = 0;

	command_copy = malloc(sizeof(char) * (num_chars + 3));
	if (command_copy == NULL)
		exit(-1);
	my_strcpy(command_copy, command);
	token = _strtok(command_copy, delim);
	while (token != NULL)
	{
		numOf_tokens++;
		token = _strtok(NULL, delim);
	}
	numOf_tokens += 2;
	*argv = malloc(sizeof(char *) * numOf_tokens);
	if ((*argv) == NULL)
	{
		exit(-1);
	}
	token = _strtok(command, delim);
	for (i = 0; token != NULL && token[0] != '#'; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
		my_strcpy((*argv)[i], token);
		token = _strtok(NULL, delim);
	}
	(*argv)[i] = NULL;
	(*argv)[++i] = NULL;
	free(command_copy);
	return (--numOf_tokens);
}
