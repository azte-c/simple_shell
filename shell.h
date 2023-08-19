#ifndef SHELL_H
#define SHELL_H
/* the ssize_t type an error message*/
void capture_input(char **prompt_user, char **user_input, ssize_t *input_bytes);
void execute_command(char *user_input);
ssize_t get_line(char *captured_input, size_t buffer_size,
		char **line_ptr, size_t *n);


#endif
