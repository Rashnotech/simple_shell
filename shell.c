#include "shell.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: arguments vector
 * Return: 0 or 1
 */
int main(int ac, char **av)
{
	char *name = av[0];

	while (1)
	{
		char *prompt = "";
		char *lineptr = NULL;
		size_t n;
		ssize_t nchar = 0;

		(void)ac;
		write(1, prompt, 0);
	/*read command from stdin*/
		nchar = getline(&lineptr, &n, stdin);
		if (nchar == 1 || lineptr[0] == ' ')
		{
			free(lineptr);
			continue;
		}
/*tokenize string into individual commands*/
		av = command_tokenizer(lineptr, &av, nchar);

		if (check(av) == 0)
		{
			free(lineptr);
			continue;
		}
		execute(av, name);
		free(lineptr);
		freearray(av);
	}
	return (0);
}

/**
 * check - check for speciall built-in commands
 * @argv: the command enterd
 * Return: 0
 */

int check(char **argv)
{
	if (_strcmp(argv[0], "exit") == 0)
		exit(98);
	else if (_strcmp(argv[0], "env") == 0)
	{
		get_environ_var();
		return (0);
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		_setenv(argv[1], argv[2]);
		return (0);
	}
	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		_unsetenv(argv[1]);
		return (0);
	}

	return (1);
}
