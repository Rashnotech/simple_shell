#include "shell.h"

/**
 * _setenv - set the environ variable to the given value
 * @var_name: name of the variable to be changed
 * @value: the value
 * Return: returns 0 at success and 1 if var_name is not found
 * -1 at error
 */

int _setenv(char *var_name, char *value)
{
	char *var;
	char **env = environ;

	var = malloc(_strlen(var_name) + _strlen(value) + 2);
	if (var == NULL)
		return (-1);
	_strcat(var, var_name);
	_strcat(var, "=");
	_strcat(var, value);

	while (*env != NULL)
	{
		if (_strncmp(*env, var_name, _strlen(var_name)) == 0)
		{
			*env = var;
			return (0);
		}
		env++;
	}
	*env = var;
	env++;
	*env = NULL;
	return (0);
}

/**
 * _unsetenv - unset and environment varieble
 * @var_name: the variable to be unseted
 * Return: 0 at success
 */

int _unsetenv(char *var_name)
{
	char **env = environ;
	char *null = NULL;

	if (var_name == NULL)
		return (-1);

	while (*env != NULL)
	{
		if (_strncmp(*env, var_name, _strlen(var_name)) == 0)
		{
			*env = null;
			return (0);
		}
		env++;
	}
	return (-1);
}
