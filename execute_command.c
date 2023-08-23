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
/*fork system call creating child process, execve executes specified command*/
	/*the return value of the fork is stored iin the process_id*/
	pid_t process_id = fork();
/*this means an error occured*/
	if (process_id == -1)
	{
		perror("fork");
		exit(-1);
	}
/*this means that is the child process*/
/*this block of code is then executed by the child process*/
	else if (process_id == 0)
	{
/*this alloactes memory to hold the command the user inputs*/
/*it holds the command and a null terminator */
		char **arguments = (char **)malloc(sizeof(char *) * 2);

		if (arguments == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		arguments[0] = user_input;
		arguments[1] = NULL;
/*execve function replaces  current process with the specified command */
		execve(user_input, arguments, NULL);
		perror("execve");
		exit(-1);
		free(*arguments);
	}
/*this block is executed by the parent and waits for chiid to finish */

	else
	{
		wait(NULL);
	}
}
