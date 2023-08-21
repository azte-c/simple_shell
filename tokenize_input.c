#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void tokenize_input(char *command, char **argsv, int *args_count)
{
	char *delimiter = " \n"; 
	char *token;

	token = strtok(command, delimiter);
	*args_count = 0;

	while (token != NULL)
	{
		argsv[*args_count] = token;
		(*args_count)++;
		token = strtok(NULL, delimiter);
	}
	argsv[*args_count] = NULL;
}
