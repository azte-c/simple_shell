#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stddef.h>
/* the ssize_t type an error message*/

void capture_input(char **user_input_ptr, ssize_t *input_bytes_ptr);
void execute_command(char *user_input);
ssize_t get_line(char *captured_input, size_t buffer_size,
		char **line_ptr, size_t *n);
void tokenize_input(char *command, char **argsv, int *args_count);
int get_path(char **argsv, int args_count);
void exit_shell(void);
void _environment(void);
char *get_env(char *env_variable);
void exit_shell(void);
#endif
