#include "shell.h"

#define BUFF_SIZE 1024

/**
 * _getline - reads an entire line from a stream
 * @lineptr: a pointer to the read line.
 * @stream: the stream to read from, e.g files or stdin.
 * Return: the number of char read.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFF_SIZE];
	static size_t pos;
	size_t i, minus_one = -1;
	static size_t nchars;
	int fd = fileno(stream);
	char *newptr;

	if (*lineptr == NULL)
	{
		*n = BUFF_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while (1)
	{
		nchars = read(fd, buffer, BUFF_SIZE);
		if (nchars == minus_one)
			return (-1);
		else if (nchars == 0)
			break;

		if (pos + nchars > *n)
		{
			*n *= 2;
			newptr = realloc(*lineptr, *n);
			if (newptr == NULL)
				return (-1);
			*lineptr = newptr;
		}

		_memcpy(*lineptr + pos, buffer, nchars);
		pos += nchars;

		for (i = 0; i < nchars; i++)
		{
			if (buffer[i] == '\n')
			{
				(*lineptr)[pos] = '\0';
				return (pos);
			}
		}
	}

	(*lineptr)[pos] = '\0';
	return (pos);
}
