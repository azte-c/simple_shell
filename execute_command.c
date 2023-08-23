#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include <string.h>
/**
 *execute_command - process and execute the user input (command)
 *@arguments: the commands recieved
 *@args_array: the array holding the arguments
 *Return: 0 success
 */

int  execute_command(char *arguments, char **args_array)
{
	char *command_path;
	char *command;
	pid_t process_id;
	int status;

	if (!args_array[0])
	{
		return (0);
	}
	command = args_array[0];
	if (strcmp(command, "env") == 0)
		print_environment();
	else if (strcmp(command, "exit") == 0)
		exit(0);
	else
	{
		command_path = location(command);
		if (!command_path)
		{
			fprintf(stderr, "%s: 1 : %s: not found\n", arguments, command);
			return (0);
		}
		process_id = fork();
		if (process_id == -1)
			perror("Error");
		else if (process_id == 0)
		{
			if (execve(command_path, args_array, NULL) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		else if (waitpid(process_id, &status, 0) == -1)
			perror("Error");
		free(command_path);
	}
	return (0);
}
