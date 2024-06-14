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
 * @shell: shell info
 * @argv: argument vector
 *
 * Return: an integer value of 0 otherwise -1
 */
int exit_cmd(shell_t *shell, char **argv)
{
	int status;
	char *name = shell->argv[0];
	int code = shell->error_code;
	pid_t parent_id;

	parent_id = getppid();
	if (argv[1] != NULL)
	{
		if (_strspn(argv[1], "0123456789") != my_strlen(argv[1]))
		{
			code = handle_exit(name, argv[0], argv[1]);
			return (code);
		}
		else
		{
			status = _atoi(argv[1]);
			if (status < 0)
			{
				code = handle_exit(name, argv[0], argv[1]);
				return (code);
			}
			else
			{
				status %= 256;
				free_command(shell);
				kill(parent_id, SIGTERM);
				exit(status);
			}
		}
	}
	free_command(shell);
	kill(parent_id, SIGTERM);
	if (code != 127 && code != 0)
		code = 2;
	exit(code);
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

/**
 * _strspn - find the position of a substring
 * @s: string of characters
 * @accept: substring to check position
 *
 * Return: an integer value of the found substring position
 */
int _strspn(char *s, char *accept)
{
	int i = 0, j;

	while (*s != '\0')
	{
		for (j = 0; accept[j]; j++)
		{
			if (*s == accept[j])
			{
				i++;
				break;
			}
			else if (accept[j + 1] == '\0')
				return (i);
		}
		s++;
	}
	return (i);
}

/**
 * _strcspn - find the position of rejected substring
 * @s: string of characters
 * @reject: substring to check
 * Return: an integer value of the reject substring position
 */
int _strcspn(char *s, char *reject)
{
	char *str = s;
	int i = 0;

	while (*str)
	{
		while (*reject)
		{
			if (*str == *reject)
				return (i);
			reject++;
		}
		str++;
		i++;
	}
	return (i);
}
