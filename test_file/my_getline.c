#include "shell.h"
#define BUFF_SIZE 1024

/**
 * _getline - reads an entire line from a stream
 * @lineptr: a pointer to the read line.
 * @n: size of lineptr
 * @fd: file descriptor
 * Return: the number of char read.
 */


ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	int size = BUFF_SIZE;
	static char buffer[BUFF_SIZE];
	size_t pos;
	size_t i;


	if (*lineptr == NULL)
	{
		*n = BUFF_SIZE;
		*lineptr = malloc((*n) * sizeof(char));
		if (*lineptr == NULL)
			return (1);
		for (i = 0; i < (*n); i++)
			(*lineptr)[i] = '\0';
	}
	pos = _readline(lineptr, n, buffer, fd, size);
	return (pos);
}

/**
 * _readline - it reads an entire line
 * @lineptr: a pointer to the string read
 * @n: size of the string pointed to by lineptr
 * @buffer: buffer to read into
 * @fd: a file discriptor to read from
 * @size: size of buffer
 *
 * Return: number of chars read
 */

size_t _readline(char **lineptr, size_t *n, char buffer[], int fd, int size)
{

	size_t pos = 0;
	size_t i, minus_one = -1;
	size_t nchars;
	char *newptr;

	while (1)
	{
		nchars = read(fd, buffer, size);
		if (nchars == minus_one || nchars == 1)
			return (1);
		else if (nchars == 0)
			return (1);

		if (pos + nchars > *n)
		{
			*n *= 2;
			newptr = _realloc(*lineptr, ((*n) / 2), *n);
			if (newptr == NULL)
				return (1);
			*lineptr = newptr;
		}

		memcpy(*lineptr + pos, buffer, nchars);
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
