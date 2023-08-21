#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include "shell.h"

/**
 *main - entry point for the program
 *Return: 0 for success, -1 for failure
 */

int main(void)
{
	while(true)
	{
		char *prompt_user;
		char *user_input;
		ssize_t input_bytes, captured_input_size;
		char *line = NULL;
		size_t line_len =0;

		capture_input(&prompt_user, &user_input, &input_bytes);
		captured_input_size = get_line(user_input, input_bytes, &line, &line_len);
		write(STDOUT_FILENO, &captured_input_size, sizeof(ssize_t));
		execute_command(user_input);

		free(prompt_user);
		free(line);
		free(user_input);
	}
	return (0);
}
