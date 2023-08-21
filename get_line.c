#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 *get_line - reads a line from an input stream
 *@line_ptr: pointer to a a pointer that is used to store the buffer address
 *@n: size of the buffer pointed to
 *@captured_input: stream from which line is to be read
 *@buffer_size: size of the buffer storing captured input
 *Return: number of characters read, (-1) if an error occurs or EOF
*/

ssize_t get_line(char *captured_input, size_t buffer_size,
		char **line_ptr, size_t *n)
{
	static char buffer[BUFFER_SIZE];
	static size_t current_buffer_pos, current_buffer_size;
	size_t new_line_pos, length_of_line, x, y, new_size;
	char *new_line;

	for (y = 0; y < buffer_size && captured_input[y] != '\0'; y++)
		buffer[y] = captured_input[y];
	current_buffer_pos = 0;
	current_buffer_size = 0;
	/* If the buffer is empty, read data from the input stream into the buffer */
	new_line_pos = current_buffer_pos; /*Get pos of the newline xter  in buffer */

	while (new_line_pos < current_buffer_size && buffer[new_line_pos] != '\n')
		new_line_pos++;

	length_of_line = new_line_pos - current_buffer_pos;
	new_size = *n + length_of_line + 1;  /** Calculate the length of the line */
	new_line = malloc(new_size);     /* Allocate memory for the line */

	if (new_line == NULL)
		return (-1);
	for (x = 0; x < *n; x++)   /* Copy data from the buffer to the new buffer */
		new_line[*n + 1] = buffer[current_buffer_pos + x];
	new_line[new_size - 1] = '\0';   /* Null terminate the line */

	free(*line_ptr);                 /* Free the old buffer */

	*line_ptr = new_line;            /* Update buffer */
	*n = new_size - 1;               /*Update buffer size(excl null terminator*/
	current_buffer_pos = new_line_pos + 1;  /* Update buffer position */

	return (length_of_line);         /* Return the number of characters read*/
}
