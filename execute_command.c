#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

/**
 *execute_command - process the user input (command)
 *@user_input: the received command
 */

void execute_command(char *user_input)
{
	pid_t process_id = fork();

	if (process_id == -1)
	{
		perror("fork");
		exit(-1);
	}
	else if (process_id == 0)
	{
		char **arguments = (char **)malloc(sizeof(char *) * 2);

		if (arguments == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		arguments[0] = user_input;
		arguments[1] = NULL;

		execve(user_input, arguments, NULL);
		perror("execve");
		exit(-1);
		free(*arguments);
	}
	else
	{
		wait(NULL);
	}
}
