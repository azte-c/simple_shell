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
	while (true)
	{
		char *user_input;
		/*char *line = NULL;*/
		/*size_t line_size =0;*/
		/*ssize_t line_len*/
		ssize_t input_bytes;
		int args_count, x;
		char *argsv[BUFFER_SIZE / 2 + 1]; /*array to store arguments*/

		capture_input(&user_input, &input_bytes);

		/*line_len = get_line(user_input, input_bytes, &line, &line_size);*/

		/*testing get_line*/
		/*printf("Line read: %s\n", line);*/
		/*printf("Line length: %ld\n", line_len);*/

		tokenize_input(user_input, argsv, &args_count);
		if (args_count > 0)
		{
			printf("Number of arguments: %d\n", args_count);
			for (x = 0; x < args_count; x++)
			{
				printf("argsv[%d]; %s\n", x, argsv[x]);
			}
			get_path(argsv, args_count);
		}
		/*execute_command(user_input);*/
		free(user_input);
		/*free(line);*/
	}
	return (0);
}
