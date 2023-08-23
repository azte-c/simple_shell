#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * path_location - returns full path of a command
 * @command: the command
 * Return: pointer to the full path where the command is
 */
char *path_location(const char *command)
{
	char *pathway;
	char *tokens;
	char *full_path;
	char *path_environment;
	int length;
	const char *delimitor = ":";

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}
	path_environment = getenv("PATH");
	if (!path_environment)
		return (NULL);
	pathway = strdup(path_environment);
	tokens = strtok(path, delimitor);
	while (tokens)
	{
		length = strlen(token) + strlen(command) + 2;
		full_path = malloc(sizeof(char) * length);
		if (!full_path)
		{
			free(pathway);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", tokens, command);
		if (access(full_path, F_OK) == 0)
		{
			free(pathway);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, delimitor);
	}
	free(pathway);
	return (NULL);
}
