#include "shell.h"

/**
 * main -This is the Entry point
 * @argc: argument counts
 * @av: The arguments passed to the programme
 * Return: 0 on success or 1 on failure
 */
int main(int argc, char **av)
{
	char *programe_name = av[0], *file = av[1];
	int errorcode = 0, fd;

	signal(SIGINT, signalHandle);
	if (argc > 1)
		file_handler(file, programe_name, argc);
	while (1)
	{
		char *input;
		ssize_t no_char = 0;

		fd = print_prompt(argc);
	/*read command from stdin*/
		input = get_input(fd, &no_char);
		if (no_char == -1)
		{
			free(input);
			if (isatty(STDIN_FILENO))
				my_putchar('\n');
			break;
		}
		if (no_char == 1 || my_strcmp(input, " ") == 0)
		{
			free(input);
			continue;
		}
	/*tokenize string into individual commands*/
		tokenizer(input, &av, no_char);
		if (av[0] == NULL)
			continue;
		if (in_built(programe_name, av, input, argc) == 0)
			continue;
		errorcode = command_execute(av, programe_name);
		free(input);
		free_arrays(&av);
	}
	normal_exit(errorcode);
	return (0);
}

/**
 * in_built - check for built-in commands
 * @name: name of programe
 * @argv: the command enterd
 * @lineptr: lineptr
 * @argc: argument counter
 * Return: 0 on if command is a built in
 */

int in_built(char *name, char **argv, char *lineptr, int argc)
{
	int status;
	(void)argc;

	if (my_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			status = _atoi(argv[1]);
			if (status < 0)
			{
				handle_exit(name, argv[0], status);
				return (0);
			}
			else
				status %= 256;
			free(lineptr);
			free_arrays(&argv);
			exit(status);
		}
		free(lineptr);
		free_arrays(&argv);
		exit(EXIT_SUCCESS);
	}

	else if (my_strcmp(argv[0], "env") == 0)
	{
		my_environ();
		if (argc == 1)
			free(lineptr);
		free_arrays(&argv);
		return (0);
	}
	else if (my_strcmp(argv[0], "setenv") == 0)
	{
		my_setenv(argv[1], argv[2]);
		if (argc == 1)
			free(lineptr);
		free_arrays(&argv);
		return (0);
	}
	else if (my_strcmp(argv[0], "unsetenv") == 0)
	{
		my_unsetenv(argv[1]);
		if (argc == 1)
			free(lineptr);
		free_arrays(&argv);
		return (0);
	}
	else if (my_strcmp(argv[0], "cd") == 0)
	{
		change_dir(argv[1]);
		if (argc == 1)
			free(lineptr);
		free_arrays(&argv);
		return (0);
	}
	return (-1);
}

/**
 * print_prompt - prints prompt depending on the mood
 * @argc: argumemt count
 * Return: file discriptor
 */

int print_prompt(int argc)
{
	int fd = STDIN_FILENO;

	if (isatty(STDIN_FILENO) && argc == 1)
		write(1, "$ ", 2);

	return (fd);
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
