#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * tokenize_input - function to tokenize arguments
 * @string: the string to be tokenizzed
 * Return: a pointer to array
*/

char **tokenize_input(char *string)
{
	char *tokens;
	char **args;
	int x;
	const char *delimitor = " \n\t\r";

	x = 0;
	args = malloc(sizeof(char *) * 300);

	if (!args)
		return (NULL);

	tokens = strtok(string, delimitor);

	while (tokens)
	{
		args[x] = strdup(tokens);
		if (!args[x])
		{
			if (args)
			{
				for (x = 0; args[x] != NULL; x++)
					free(args[x]);

				free(args);
			}
			return (NULL);
		}

		tokens = strtok(NULL, delimitor);
		x++;
	}

	args[x] = NULL;
	return (args);
}
