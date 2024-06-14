#include "shell.h"
/**
 * tokenizer - for tokenizing of strings
 * @shell: shell info
 * @command: string to be tokenized
 * @num_chars: the number chars written
 * Return: An array of string
 */

char ***tokenizer(shell_t *shell, char *command, ssize_t num_chars)
{
	char *command_copy = NULL, *token, ***commands = NULL;
	char *delim = "\r\n ", **argv;
	int i, j = 0, num_commands = 1, numOf_tokens = 0;

	command_copy = malloc(sizeof(char) * (num_chars + 3));
	my_strcpy(command_copy, command);
	token = my_strtok(command_copy, delim);
	while (token != NULL)
	{
		numOf_tokens++;
		if (my_strcmp(token, "&&") == 0 || my_strcmp(token, "||") == 0)
			num_commands++;
		token = my_strtok(NULL, delim);
	}
	shell->num_commands = num_commands;
	commands = malloc(sizeof(char **) * (num_commands + 1));
	token = my_strtok(command, delim);
	while (token != NULL && token[0] != '#')
	{
		argv = malloc(sizeof(char *) * (numOf_tokens + 1));
		argv[0] = malloc(sizeof(char) * (my_strlen(token) + 1));
		my_strcpy(argv[0], token);
		token = my_strtok(NULL, delim);
		for (i = 1; (my_strcmp(token, "&&") != 0)  && (my_strcmp(token, "||")
					!= 0) && token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (my_strlen(token) + 1));
			my_strcpy(argv[i], token);
			token = my_strtok(NULL, delim);
		}
		argv[i] = NULL;
		commands[j] = argv;
		j++;
	}
	commands[j] = NULL;
	free(command_copy);
	return (commands);
}
