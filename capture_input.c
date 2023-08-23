#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
  *exit_shell - exits the shell
*/

void exit_shell(void)
{
	char exit_output[] = "Exiting the shell ... \n";

	write(STDOUT_FILENO, exit_output, sizeof(exit_output) - 1);
	exit(0);
}

/**
 *capture_input - prompts the user and captures the input
 *@user_input_ptr:pointer to the user input
 *@input_bytes_ptr: pointer to the input bytes
 */
void capture_input(char **user_input_ptr, ssize_t *input_bytes_ptr)
{
	char *user_input;/*user_input will hold input from user*/
	ssize_t input_bytes;/* store the number of bytes read*/
	const char *prompt = "# ";

	write(STDOUT_FILENO, prompt, 2);
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
		free(user_input);
		exit(0);
	}
	else if (input_bytes == -1)
	{
		perror("read");
		free(user_input);
		exit(-1);
	}
	user_input[input_bytes - 1] = '\0';

	if (strcmp(user_input, "exit") == 0)
		exit_shell();

	*user_input_ptr = user_input;
	*input_bytes_ptr = input_bytes;
}
