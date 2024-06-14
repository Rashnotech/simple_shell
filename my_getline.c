#include "shell.h"
#define BUFF_SIZE 1024

/**
 * _getline - reads an entire line from a stream
 * @shell: shell info
 * @lineptr: a pointer to the read line.
 * @n: size of lineptr
 *
 * Return: the number of char read.
 */


ssize_t _getline(shell_t *shell, char **lineptr, size_t *n)
{
	size_t pos = 0;

	if (*lineptr == NULL)
	{
		*n = BUFF_SIZE;
		*lineptr = malloc((*n) * sizeof(char));
		if (*lineptr == NULL)
			return (-1);
	}
	pos = _readline(shell, lineptr, n);
	return (pos);
}

/**
 * _readline - it reads an entire line
 * @shell: shell info
 * @lineptr: a pointer to the string read
 * @n: size of the string pointed to by lineptr
 *
 * Return: number of chars read
 */

size_t _readline(shell_t *shell, char **lineptr, size_t *n)
{
	static char buffer[BUFF_SIZE];
	static size_t bufpos, bufsize;
	size_t pos = 0;
	size_t nchars;
	char *newptr;

	while (1)
	{
		if (bufpos >= bufsize)
		{
			nchars = read(shell->fd, buffer, BUFF_SIZE - 1);
			if (nchars <= 0 && pos == 0)
				return (-1);
			else if (nchars <= 0)
				break;
			bufsize = nchars;
			bufpos = 0;
		}

		if (pos >= *n - 1)
		{
			*n *= 2;
			newptr = _realloc(*lineptr, ((*n) / 2), *n);
			if (newptr == NULL)
				return (-1);
			*lineptr = newptr;
		}
		(*lineptr)[pos++] = buffer[bufpos++];
		if ((*lineptr)[pos - 1] == '\n')
			break;
	}

	(*lineptr)[pos++] = '\0';
	return (pos);
}
