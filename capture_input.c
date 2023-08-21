#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
 *capture_input - prompts the user and captures the input
 *@user_input_ptr:pointer to the user input
 *@input_bytes_ptr: pointer to the input bytes
 */
void capture_input(char **user_input_ptr, ssize_t *input_bytes_ptr)
{
	char *prompt_user, *user_input;
	ssize_t input_bytes;

	prompt_user = (char *)malloc(sizeof(char) * 2);
	prompt_user[0] = '#';
	prompt_user[1] = '\0';

	write(STDOUT_FILENO, prompt_user, 1);
	user_input = (char *)malloc(sizeof(char) * BUFFER_SIZE);

	if (user_input == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	input_bytes = read(STDIN_FILENO, user_input, BUFFER_SIZE);

	if (input_bytes == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(prompt_user);
		free(user_input);
		exit(0);
	}
	else if (input_bytes == -1)
	{
		perror("read");
		free(prompt_user);
		free(user_input);
		exit(-1);
	}
	user_input[input_bytes - 1] = '\0';
	free(prompt_user);

	*user_input_ptr = user_input;
	*input_bytes_ptr = input_bytes;
}
