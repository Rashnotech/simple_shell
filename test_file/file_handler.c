#include "shell.h"

/**
 * file_handler - handles commands from file
 * @file: - the files that contains command
 * @programe_name: the name of the shell
 * @argc: the numbers of arguments
 * Return: void
 */

void file_handler(char *file, char *programe_name, int argc)
{
	char *token = NULL, *input, **argv;
	int fd, errorcode;
	ssize_t no_char;
	

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		error_puts(programe_name);
		error_puts(": 0: cannot open ");
		error_puts(file);
		error_puts(": No such file\n");
		exit(2);
	}

	input = get_input(fd, &no_char);
	token = _strtok(input, "\n");
	while (token != NULL)
	{
		tokenizer(token, &argv, no_char);
		token = _strtok(NULL, "\n");
		if (in_built(programe_name, argv, input, argc) == 0)
			continue;
		errorcode = command_execute(argv, programe_name);
		free_arrays(&argv);
	}
	free(input);
	normal_exit(errorcode);
}
