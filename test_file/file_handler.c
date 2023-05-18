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
	

	fd = open(file, O_RDONLY);

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
