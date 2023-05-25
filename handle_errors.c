#include "shell.h"

/**
 * handle_error - print errors
 * @name: name of the programe
 * @cmd: the command passed command
 */
int handle_error(char *name, char *cmd)
{
	static int i = 1;

	error_puts(name);
	error_putchar(':');
	error_putchar(' ');
	errorput_number(i);
	error_putchar(':');
	error_putchar(' ');
	error_puts(cmd);
	error_putchar(':');
	error_putchar(' ');
	error_puts("not found");
	error_putchar('\n');
	i++;
	return (127);
}

/**
 * handle_exit - print exit error
 * @name: program name
 * @cmd: command argument
 * @code: status code
 */
int handle_exit(char *name, char *cmd, char *code)
{
	static int i = 1;

	error_puts(name);
	error_putchar(':');
	error_putchar(' ');
	errorput_number(i);
	error_putchar(':');
	error_putchar(' ');
	error_puts(cmd);
	error_putchar(':');
	error_puts(" Illegal number");
	error_putchar(':');
	error_putchar(' ');
	error_puts(code);
	error_putchar('\n');
	i++;
	return (2);
}
