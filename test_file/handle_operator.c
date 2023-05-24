#include "shell.h"

/**
 * handle_operators - Handles command operator
 * @input: entry command
 * @name: programme name
 * @no_char: number of characters
 * @argc: argument counter
 * @delim: delimeters
 * Return: an integer value of 0 otherwise -1
 */
int handle_operators(char *input, char *name, ssize_t no_char,
		int argc, char *delim)
{
	char **argv = NULL, *token, *input_copy;
	int ret;

	argc = 2;
	input_copy = my_strdup(input);
	token = _strtok(input_copy, delim);
	while (token != NULL)
	{
		tokenizer(token, &argv, no_char);
		token = _strtok(NULL, delim);

		if (argv[0] == NULL)
			continue;
		if (in_built(name, argv, input, argc) == 0)
			continue;
		ret = command_execute(argv, name);
		if ((ret != 0 && my_strcmp(delim, "&&") == 0)
				|| (ret == 0 && my_strcmp(delim, "||") == 0))
			break;
		free_arrays(&argv);
	}
	free(input_copy);
	free(input);
	return (0);
}

<<<<<<< HEAD
/**
 * print_aliases - print alias commands and values
 * @node: struct node alias
 * Return: an integer value counter
 */
int print_aliases(const alias *node)
{
	int index = 0;

	while (node != NULL)
	{
		my_puts(node->name);
		my_putchar(' ');
		my_puts(node->value);
		my_putchar(10);
		node = node->next;
		index++;
	}
	return (index);
}

/**
 * add_alias - add alias command to list
 * @node: struct node
 * @name: alias name
 * @value: alias value
 * Return: struct type alias
 */
alias *add_alias(alias **node, char *name, char *value)
{
	alias *new_node;

	new_node = malloc(sizeof(alias));
	if (!new_node)
		return (NULL);
	_strncpy(new_node->name, name, MAX_NAME);
	_strncpy(new_node->value, value, MAX_VALUE);
	new_node->next = *node;
	*node = new_node;
	return (new_node);
}

/**
 * execute_alias - perform execution on aliases or print list
 * @node: struct node
 * @argv: argument vector
 */
void execute_alias(alias **node, char **argv)
{
	alias *head_node;
	char *name, *value;

	name = argv[1];
	value = argv[2];
	if (name != NULL && value != NULL)
		add_alias(node, name, value);
	else
	{
		head_node = *node;
		while (head_node != NULL)
		{
			if (my_strcmp(head_node->name, name) == 0)
			{
				value = head_node->value;
				break;
			}
			head_node = head_node->next;
		}
	}
}
=======
>>>>>>> bourne
