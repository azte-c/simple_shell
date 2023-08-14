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
		ssize_t input_bytes;

		capture_input(&prompt_user, &user_input, &input_bytes);
		execute_command(user_input);

		free(prompt_user);
		free(user_input);
	}
	return (0);
}
