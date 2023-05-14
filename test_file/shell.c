#include "shell.h"

/**
 * main -This is the Entry point
 * @argc: argument counts
 * @av: The arguments passed to the programme
 * Return: 0 on success or 1 on failure
 */
int main(int argc, char **av)
{
	char *programe_name = av[0];
	int errorcode = 0;
	int fd;

	while (1)
	{
		char *input;
		ssize_t no_char = 0;
		int no_of_cmd;

		fd = print_prompt(argc, av);
	/*read command from stdin*/
		input = get_input(fd, &no_char);
		if (no_char == -1)
		{
			free(input);
			my_putchar('\n');
			break;
		}
		if (no_char == 1 || input[0] == ' ')
		{
			free(input);
			continue;
		}
	/*tokenize string into individual commands*/
		no_of_cmd = tokenizer(input, &av, no_char);
		if (in_built(av, input, no_of_cmd) == 0)
			continue;
		errorcode = command_execute(av, programe_name);
		free(input);
		free_arrays(&av);
	}
	if (errorcode == 1)
		exit(EXIT_FAILURE);
	else
	exit(EXIT_SUCCESS);
}

/**
 * in_built - check for built-in commands
 * @argv: the command enterd
 * @lineptr: lineptr
 * Return: 0 on if command is a built in
 */

int in_built(char **argv, char *lineptr, int argc)
{
	char *null = NULL;

	if (my_strcmp(argv[0], "exit") == 0)
	{
		/*if (argv[1] != NULL)
		{
			free(lineptr);
			free_arrays(&argv);
			exit((int)argv[1]);
		}*/
		free(lineptr);
		free_arrays(&argv);
		exit(EXIT_SUCCESS);

	}

	else if (my_strcmp(argv[0], "env") == 0)
	{
		my_environ();
		free(lineptr);
		free_arrays(&argv);
		return (0);
	}
	else if (my_strcmp(argv[0], "setenv") == 0)
	{
		my_setenv(argv[1], argv[2]);
		free(lineptr);
		free_arrays(&argv);
		return (0);
	}
	else if (my_strcmp(argv[0], "unsetenv") == 0)
	{
		my_unsetenv(argv[1]);
		free(lineptr);
		free_arrays(&argv);
		return (0);
	}

	return (-1);
}

/**
 * print_prompt - prints prompt depending on the mood
 * @argc: argumemt count
 * @argv: argument array
 * Return: file discriptor
 */

int print_prompt(int argc, char **argv)
{
	int fd = STDIN_FILENO;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		return (fd);
	}

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
/*	pid_t my_pid = getpid();*/

	(void)fd;
	*no_char = (_getline(&lineptr, &n, fd));

	return (lineptr);
}


