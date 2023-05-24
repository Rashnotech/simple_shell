#include "shell.h"
/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: an integer value otherwise 0
 */
int _atoi(const char *s)
{
	int i, d, n, len, f, digit;

	i = d = n = len = f = digit = 0;
	len = my_strlen(s);

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);
	return (n);
}

/**
 * exit_cmd - handle exit command
 * @name: name for program
 * @argv: argument vector
 * @lineptr: line pointer
 *
 * Return: an integer value of 0 otherwise -1
 */
int exit_cmd(char *name, char **argv, char *lineptr)
{
	int status;
	pid_t parent_id;

	parent_id = getppid();
	if (argv[1] != NULL)
	{
		status = _atoi(argv[1]);
		if (status < 0)
		{
			handle_exit(name, argv[0], status);
			return (0);
		}
		else
		{
			status %= 256;
			free(lineptr);
			free_arrays(&argv);
			kill(parent_id, SIGTERM);
			exit(status);
		}
	}
	else
	{
		free(lineptr);
		free_arrays(&argv);
		status = kill(parent_id, SIGTERM);
		if (status == -1)
			perror("Error existing");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/**
 * clean_up - clean up argument vector and line pointer
 * @argv: argument vector
 * @lineptr: line pointer
 * @argc: argument counter
 * Return: an integer value of 0
 */
int clean_up(char **argv, char *lineptr, int argc)
{
	if (argc == 1)
		free(lineptr);
	free_arrays(&argv);
	return (0);
}
