#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
extern char **environ;

void exit_shell(void);
int execute_command(char *arguments, char **args_array);
ssize_t get_line(char *captured_input, size_t buffer_size,
		char **line_ptr, size_t *n);
char *path_location(const char *command);
void print_environment(void);
void prompt_user(void);
char **tokenize_input(char *string);
#endif
