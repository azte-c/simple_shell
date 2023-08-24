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
/*function*/
		execute_command(argv[0], arguments);
		buffer = NULL;
		length = 0;
		free(buffer);
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
argv[x] = "x";
}
