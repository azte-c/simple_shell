#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define MAX_PATHS 200

/**
 *get_path - checks the path to be followed into directories
 *@argsv: arrays of strings forming the command
 *@args_count: number of arguments in the command
 */
void get_path(char *argsv[], int *args_count)
{
	char *path = getenv("PATH");
	char *delimiter, *tokenize_path;

	if (path == NULL)
	{
		perror("getenv");
		exit(-1);
	}

	delimiter = ":";
	/*change NULL to path*/
	tokenize_path = strtok(path, delimiter);

	while (tokenize_path != NULL)
	{
		argsv[(*args_count)++] = tokenize_path;
		tokenize_path = strtok(NULL, delimiter);
	}
}
