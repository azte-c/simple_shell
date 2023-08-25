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
	char *command_path, *command;/*the path to the command is stored here*/
	pid_t process_id;
	int status;

	if (!args_array[0])
		return (0);
	command = args_array[0];/*puts in the initial command*/
	if (strcmp(command, "env") == 0)/*test if command is env*/
		print_environment();/*calls the function*/
	else if (strcmp(command, "exit") == 0)
	{
		exit_shell();
	}
	else
	{
		command_path = path_location(command);
		if (!command_path)
		{
			fprintf(stderr, "%s: No such file or directory\n", arguments);
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
		else if (wait(&status) == -1)
			perror("Error");
		free(command_path);
	}
	return (0);
}
