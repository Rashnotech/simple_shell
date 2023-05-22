#include "shell.h"
/**
 * change_dir - change directory command
 * @dir: directory name
 */
void change_dir(char *dir)
{
	char cwd[PATH_MAX], *path, *old_pwd;
	int retval;

	if (dir != NULL)
	{
		if (my_strcmp(dir, "-") == 0)
		{
			old_pwd = my_getenv("OLDPWD");
			path = my_getenv("PWD");
			_setenv("PWD", old_pwd, 1);
			chdir(old_pwd);
			_setenv("OLDPWD", path, 1);
		}
		else
		{
			path = my_getenv("PWD");
			retval = chdir(dir);
			if (retval == 0)
			{
				_setenv("OLDPWD", path, 1);
				_setenv("PWD", getcwd(cwd, sizeof(cwd)), 1);
			}
			else
				perror("Directory not found");
		}
	}
	else
	{
		path = my_getenv("HOME");
		if (path == NULL)
			perror("HOME not set");
		_setenv("OLDPWD", getcwd(cwd, sizeof(cwd)), 1);
		_setenv("PWD", path, 1);
		chdir(path);
	}
}

/**
 * _setenv - set/add environment variable
 * @name: environment name
 * @value: environment value
 * @overwrite: an integer value 0 on replacement otherwise 1 for overwrite
 *
 * Return: an integer value of 0 on success otherwise -1 for error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *x_env;
	char *new_env = NULL;
	int len, status;
	static int i = 0;
	if (name == NULL || value == NULL)
		return (-1);
	x_env = _getenv(name);
	if (x_env != NULL && overwrite == 0)
		return (-1);
	len = my_strlen(name) + my_strlen(value) + 2;

	new_env = malloc(sizeof(char) * len);
	if (!new_env)
	{
		perror("Memory allocation failed");
		return (-1);
	}
	i++;
	snprintf(new_env, len, "%s=%s", name, value);
	status = putenv(new_env);
	if (status != 0)
	{
		free(new_env);
		return (-1);
	}
	return (0);
}

/**
 * _getenv - get environment variable
 * @name: environment name
 *
 * Return: path name found otherwise NULL
 */
char *_getenv(const char *name)
{
	int i = 0, index;
	char *env;

	while (environ[i] != NULL)
	{
		env = environ[i];
		if (my_strncmp(env, name, my_strlen(name)) == 0)
		{
			index = _strchr(env, '=') - env;
			return (env + index + 1);
		}
		i++;
	}
	return (NULL);
}

/**
 * _strchr - find if a character is in a string
 * @str: string of character to make search
 * @c: character to seek
 *
 * Return: found string otherwise NULL
 */
char *_strchr(char *str, char c)
{
	int i = 0;
	
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return (&str[i]);
	}
	return (NULL);
}

/**
 * signalHandler - handle ctrl c signal
 * @signum: signal number
 *
 * Return: return an integer value
 */
void signalHandle(int signum)
{
	(void)signum;
	signal(SIGINT, signalHandle);
	fflush(stdout);
	my_putchar(10);
	my_puts("$ ");
}
