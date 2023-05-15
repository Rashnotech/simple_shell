#include "shell.h"

/**
 * handle_error - print errors
 * @name: name of the programe
 * @cmd: the command passed command
 */

void handle_error(char *name, char *cmd)
{
	static int i = 1;

	my_puts(name);
	my_putchar(':');
	my_putchar(' ');
	put_number(i);
	my_putchar(':');
	my_putchar(' ');
	my_puts(cmd);
	my_putchar(':');
	my_putchar(' ');
	my_puts("not found");
	my_putchar('\n');

	i++;

}

/**
 * handle_exit - print exit error
 * @status: status code
 */
void handle_exit(char *name, char *cmd, int code)
{
	static int i = 1;

	my_puts(name);
	my_putchar(':');
	my_putchar(' ');
	put_number(i);
	my_putchar(':');
	my_putchar(' ');
	my_puts(cmd);
	my_putchar(':');
	my_puts(" Illegal number");
	my_putchar(':');
	my_putchar(' ');
	put_number(code);
	my_putchar('\n');
	i++;
}
