#include "shell.h"
/**
 * getpath - get the absolute path of a command
 * @cmd: command
 * Return: the absolute path of the command
 */
char *getpath(char *cmd)
{
	 char *paths, *paths1;
	char *token;
	char *fulpath = NULL;

	if (cmd == NULL)
		return (NULL);
	if (access(cmd, X_OK) != -1)
	{
		return (cmd);
	}
	paths1 = getenv("PATH");
	paths = _strdup(paths1);
	token = strtok(paths, ":");
	while (token != NULL)
	{
		fulpath = malloc((_strlen(token) + _strlen(cmd) + 2) * sizeof(char));
		if (fulpath != NULL)
		{
			_strcpy(fulpath, token);
			_strcat(fulpath, "/");
			_strcat(fulpath, cmd);
		}
		if (access(fulpath, X_OK) != -1)
		{
			free(paths);
			return (fulpath);
		}
		free(fulpath);
		token = strtok(NULL, ":");
	}
	free(paths);
	return (NULL);
}
