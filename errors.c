#include "monty.h"
/**
 * push_err - Prints stack push error
 * @file: file descriptor
 * @line: Current line
 * @stack: Stackin action
 * @count: line count
 */
void push_err(FILE *file, char *line, stack_t *stack, unsigned int count)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", count);
	free(line);
	free_list(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
/**
 * option_err - Prints stack push error
 * @file: file descriptor
 * @line: Current line
 * @stack: Stackin action
 * @item: Line count
 * @count: instruction
 */
void option_err(FILE *file, char *line, stack_t *stack, char *count,
		unsigned int item)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", item, count);
	free(line);
	free_list(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
