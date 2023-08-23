#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stddef.h>

extern char **environment;

int execute_command(char *arguments, char **args_array);
char *path_location(const char *command);
void print_environment(void);
void prompt_user(void);
char **tokenize_input(char *string);
#endif
