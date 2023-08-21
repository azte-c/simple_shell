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
 *Return: 0 for success, -1 for failure
 */

int main(void)
{
	while(true)
	{
		char *user_input;
		char *line = NULL;
		size_t line_size =0;
		ssize_t line_len, input_bytes;

		capture_input(&user_input, &input_bytes);

		line_len = get_line(user_input, input_bytes, &line, &line_size);
		
		execute_command(user_input);

		printf("Line read: %s\n", line);
		printf("Line length: %ld\n", line_len);

		free(user_input);
		free(line);
	}
	return (0);
}
