#include "shell.h"

/**
 * error_putchar - writes char c to stdout
 * @c: The char to be printed
 * Return: 0 on success
 * On error, -1 is returned
 */
int error_putchar(char c)
{
	return (write(2, &c, 1));
}

/**
 * error_puts - prints a string of char to stdout
 * @str: the string of char to be printed
 * Return: the length of the string
 */
void error_puts(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		error_putchar(str[i]);
		i++;
	}
}

/**
 * errorput_number - for writing int
 * @i: number to be written
 * Return: 0 on success or 1 on failure
 */
int errorput_number(int i)
{
	if (i < 0)
	{
		error_putchar('-');
		i = -i;
	}
	if (i < 10)
	{
		error_putchar(i + '0');
		return (0);
	}
	put_number(i / 10);
	error_putchar((i % 10) + '0');
	return (1);
}
