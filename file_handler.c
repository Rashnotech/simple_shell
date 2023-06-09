#include "shell.h"

/**
 * file_handler - handles commands from file
 * @file: - the files that contains command
 * @programe_name: the name of the shell
 * @argc: the numbers of arguments
 */
void file_handler(char *file, char *programe_name, int argc)
{
	char *token = NULL, *input, **argv;
	int fd, err = 0;
	ssize_t no_char;

	fd = open(file, O_RDONLY);
	if (fd == -1)
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
		if (argv[0] == NULL)
			continue;
		if (in_built(programe_name, argv, input, argc, err) == 0)
			continue;
		err = command_execute(argv, programe_name);
		free_arrays(&argv);
	}
	free(input);
	normal_exit(err);
}
