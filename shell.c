#include "shell.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: arguments vector
 * Return: 0 or 1
 */
int main(int ac, char **av)
{
	while (1)
	{
	char *name = av[0];
	char *prompt = "($) ";
	char *lineptr = NULL;
	size_t n;
	ssize_t nchar = 0;

		(void)ac;
		write(1, prompt, 5);
	/*read command from stdin*/
		nchar = getline(&lineptr, &n, stdin);
		if (nchar == 1)
		{
			free(lineptr);
			continue;
		}
/*tokenize string into individual commands*/
		av = command_tokenizer(lineptr, &av, nchar);

		if (check(av[0], av[1], av[2]) == 0)
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
 * @arg0: the command enterd
 * @arg1: the first argument to the command
 * @arg2: the second argument to the comnand
 * Return: 0 on success 1 on failure
 */

int check(char *arg0, char *arg1, char *arg2)
{
	if (_strcmp(arg0, "exit") == 0)
		exit(98);
	else if (_strcmp(arg0, "env") == 0)
	{
		get_environ_var();
		return (0);
	}
	else if (_strcmp(arg0, "setenv") == 0)
	{
		_setenv(arg1, arg2);
		return (0);
	}
	if (_strcmp(arg0, "unsetenv") == 0)
	{
		_unsetenv(arg1);
		return (0);
	}

	return (1);
}
