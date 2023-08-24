#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
 *main - entry point for the program
 *@argc: no of arguments
 *@argv: array holding the arguments
 *Return: 0 for success, -1 for failure
 */

int main(int argc, char **argv)
{

	char **arguments;
	ssize_t status;
	char *buffer = NULL;
	size_t length;
	int x;
	char *full_path = path_location(argv[0]);

	while (1)
	{
		prompt_user();/*function*/
		status = getline(&buffer, &length, stdin);
		if (status == -1)
		{
			free(buffer);
			exit(0);
		}
		/*function*/
		arguments = tokenize_input(buffer);
		if (arguments == NULL)
		{
			continue;
		}
		if (full_path != NULL)
		{
			execute_command(full_path, arguments);
		}
		else
		{
			printf("Path not found. \n");
		}
		for (x = 0; arguments[x] != NULL; x++)
			free(arguments[x]);
		free(arguments);
		free(buffer);
		length = 0;
		buffer = NULL;
	}
	if (arguments)
	{
		for (x = 0; arguments[x] != NULL; x++)
		{
			free(arguments[x]);
		}
	free(arguments);
	}
	return (0);
argc++;
}
