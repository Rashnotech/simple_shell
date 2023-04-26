#include "shell.h"

/**
 * _puterror - print errors
 * @name: programme name
 * @cmd: command
 */

void _puterror(char *name, char *cmd)
{
	_puts(name);
	_putchar(':');
	_putchar(' ');
	_putchar('1');
	_putchar(':');
	_putchar(' ');
	_puts(cmd);
	_putchar(':');
	_putchar(' ');
	_puts("not found");
	_putchar('\n');
	
}
