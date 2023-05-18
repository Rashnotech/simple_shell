#include "shell.h"
/**
 * my_getpath - for geting the absolute path of a command
 * @cmd: the command
 * Return: absolute path of the command or NULL
 */

char *my_getpath(char *cmd)
{
	char *token;
	char *full_path = NULL;
	char *paths, *paths_1 = NULL;

	if (cmd == NULL)
		return (NULL);
	if (access(cmd, X_OK) != -1)
	{
		return (cmd);
	}
	paths_1 = my_getenv("PATH");
	if (paths_1 == NULL)
		return (NULL);
	paths = my_strdup(paths_1);
	token = strtok(paths, ":");

	while (token != NULL)
	{
		full_path = malloc((my_strlen(token) + my_strlen(cmd) + 2) * sizeof(char));
		if (full_path != NULL)
		{
			my_strcpy(full_path, token);
			my_strcat(full_path, "/");
			my_strcat(full_path, cmd);
		}
		if (access(full_path, X_OK) != -1)
		{
			free(paths);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(paths);
	return (NULL);
}
