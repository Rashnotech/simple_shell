#include "shell.h"

/**
 * my_environ - get the enironment variebles
 * Return: void
 */
void my_environ(void)
{
	unsigned int envlen, i = 0;
	char **env = environ;

	while (env[i] != NULL)
	{
		envlen = my_strlen(env[i]);

		write(1, env[i], envlen);
		write(1, "\n", 1);
		env++;

	}
}

/**
 * my_setenv - for seting the environ variable to the given value
 * @var_name: name of the variable to be changed or created
 * @value: the value to be assigned
 * Return: returns 0 at success and
 * -1 at error
 */

int my_setenv(char *var_name, char *value)
{
	int i;
	char var[1024];
	char **env_var = environ;
	int len;

	if (var_name != NULL)
	{
		if (value == NULL)
			len = (my_strlen(var_name) + 2);
		else
			len = (my_strlen(var_name) + my_strlen(value) + 2);


		/*var = malloc(sizeof(char) * len);
		if (var == NULL)
			return (1);*/

		for (i = 0; i < 1024; i++)
			var[i] = '\0';
		var[--len] = '\0';
	/*printf("%d", len);
	printf("%s %s", var_name, value);
	printf("%lu", sizeof(var));*/


		my_strcat(var, var_name);
		my_strcat(var, "=");
		if (value != NULL)
			my_strcat(var, value);

		while (*env_var != NULL)
		{
			if (my_strncmp(*env_var, var_name, my_strlen(var_name)) == 0)
			{
				*env_var = var;
				return (0);
			}
			env_var++;
		}
		*env_var = var;
		env_var++;
		*env_var = NULL;
	}
	return (0);
}

/**
 * my_unsetenv - for deleting an environ varieble
 * @var_name: the variable to be deleted
 * Return: 0 at success and -1 on failure
 */

int my_unsetenv(char *var_name)
{
	char **env_var = environ;
	char *null = NULL;

	if (var_name == NULL)
		return (-1);

	while (*env_var != NULL)
	{
		if (my_strncmp(*env_var, var_name, my_strlen(var_name)) == 0)
		{
			*env_var = null;
			return (0);
		}

		env_var++;
	}

	return (-1);
}

/**
 * my_getenv - to get a specifide environment variable
 * @var_name: the name of the environ variable.
 * Return: a string containing the value of environ variable
 */

char *my_getenv(char *var_name)
{
	char **env = environ;
	int len = my_strlen(var_name);

	while (*env != NULL)
	{
		if (my_strncmp(*env, var_name, len) == 0)
			return ((&(*env)[len + 1]));
		env++;
	}
	return (NULL);
}
