#include "shell.h"

/**
 * main -This is the Entry point
 * @argc: argument counts
 * @av: The arguments passed to the programme
 * Return: 0 on success or 1 on failure
 */
int main(int argc, char **av)
{
	shell_t shell_info = {0}, *shell = &shell_info;
	char *input;
	int  check;
	ssize_t no_char = 0;

	initialize(shell, argc, av);
	signal(SIGINT, signalHandle);
	while (1)
	{
		if (shell->is_interactive)
			print_prompt();
		input = get_input(shell->fd, &no_char);
		check = check_input(shell, no_char, input);
		if (check == -1)
			break;
		if (check == 1)
			continue;

		continue_main(shell, input, no_char);
	}
	normal_exit(shell->error_code);
	return (0);
}

/**
 * continue_main - continue the maun funtion
 * @shell: the shell information
 * @input: the command
 * @no_char: no of char read as input
 * Return: 0 at success
 */

int continue_main(shell_t *shell, char *input, size_t no_char)
{
	char ***commands, **command;
	int code = 0, i, can_execute = 1;

	commands = tokenizer(shell, input, no_char);
	if (commands == NULL || commands[0] == NULL || commands[0][0] == NULL)
		return (0);

	for (i = 0; i < shell->num_commands; i++)
	{
		command = commands[i];

		if (my_strcmp(command[0], "&&") == 0)
		{
			if (code != 0 && i != 0)
				can_execute = 0;
			++command;
		}

		else if (my_strcmp(command[0], "||") == 0)
		{
			if (shell->error_code == 0 && i != 0)
				can_execute = 0;
			++command;
		}
		if (can_execute)
		{
			code = in_built(shell, command, input);

			if (code == 0 || code == 2)
				continue;
			code = command_execute(command, shell->argv[0]);
			shell->error_code = code;
		}

	}
	free(input);
	free_command(shell, commands);
	shell->error_code = code;
	return (shell->error_code);
}

/**
 * in_built - check for built-in commands
 * @shell: the shell information
 * @argv: the command enterd
 * @lineptr: lineptr
 * Return: 0 on if command is a built in
 */
int in_built(shell_t *shell, char **argv, char *lineptr)
{
	int status = 0;

	if (my_strcmp(argv[0], "exit") == 0)
	{
		shell->error_code = exit_cmd(
		shell->argv[0], argv, lineptr, shell->error_code);
		return (status);
	}
	else if (my_strcmp(argv[0], "env") == 0)
		my_environ();
	else if (my_strcmp(argv[0], "setenv") == 0)
		my_setenv(argv[1], argv[2]);
	else if (my_strcmp(argv[0], "unsetenv") == 0)
		my_unsetenv(argv[1]);
	else if (my_strcmp(argv[0], "cd") == 0)
		change_dir(argv[1]);
	else
		return (-1);
	if (shell->argc > 1)
		shell->error_code = clean_up(argv, lineptr, shell->argc);
	return (status);
}

/**
 * print_prompt - prints prompt depending on the mood
 * Return: void
 */
void print_prompt(void)
{
	write(1, "$ ", 2);
}

/**
 * get_input - for getting input from user
 * @fd: the file discriptor
 * @no_char: address of the no. of char read
 * Return: returns the string of input
 */
char *get_input(int fd, ssize_t *no_char)
{
	char *lineptr = NULL;
	size_t n;

	*no_char = (_getline(&lineptr, &n, fd));
	return (lineptr);
}
