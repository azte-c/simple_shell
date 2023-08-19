#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

/**
 *capture_input - prompts the user and captures the input
 *@prompt_user: stores the prompt to be displayed to the user
 *@user_input: stores the user's input(command)
 *@input_bytes: store the number of bytes from the user's input
 */

void capture_input(char **prompt_user, char **user_input, ssize_t *input_bytes)
{
	*prompt_user = (char *)malloc(sizeof(char) * 2);
	(*prompt_user)[0] = '#';
	(*prompt_user)[1] = '\0';

	write(STDOUT_FILENO, *prompt_user, 1);

	*user_input = (char *)malloc(sizeof(char) * 256);

	if (*user_input == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	*input_bytes = read(STDIN_FILENO, *user_input, 256);

	if (*input_bytes == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	else if (*input_bytes == -1)
	{
		perror("read");
		exit(-1);
	}
	(*user_input)[*input_bytes - 1] = '\0';
}
