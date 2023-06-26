#include "monty.h"
/*int s_elem;*/
/**
 * token_it - Reads the monty file.
 * @path: Path to the monty file.
 */
void token_it(char *path)
{
	file_line fpath;
	/*int s_elem;*/
	int jump_result;
	size_t buffer = 0, inc = 0;
	char *instruction = NULL, *element = NULL;
	stack_t *stack = NULL;

	fpath.path = fopen(path, "r");
	if (fpath.path)
	{
		while (getline(&fpath.line, &buffer, fpath.path) != -1)
		{
			inc++;
			instruction = strtok(fpath.line, " \n\r\t$");
			if (!instruction)
			{
				free(instruction);
				continue;
			}
			if (*instruction == '#')
				continue;
			element = strtok(NULL, " \n\t\r$");
			/*printf("%s", element);*/
			/*exit(1);*/
			jump_result = jump(&stack, instruction, element, inc);
			if (jump_result == 1)
			{
				push_err(fpath.path, fpath.line, stack, inc);
			} else if (jump_result == -1)
			{
				option_err(fpath.path, fpath.line, stack, instruction, inc);
			}
		}
		free(fpath.line);
		free_list(stack);
		fclose(fpath.path);

	}
}
/**
 * jump - Selects funtion based on the command
 * @stack: Stack for action
 * @inst: Instruction to the program
 * @elem: Element to be inserted
 * @c: Line count
 * Return: Zero on Success
 */
int jump(stack_t **stack, char *inst, char *elem, size_t c)
{
	size_t idx = 0;
	instruction_t option[] = {
		{"pall", print_all},
		{"pop", pop_elem},
		{"push", push_elem},
		{"pint", print_int},
		{"swap", swap_elem},
		{"nop", do_none},
		{"add", add},
		{"mul", mul},
		{"sub", sub},
		{"mod", mod},
		/*{div, div},*/
		{NULL, NULL}
	};

	while (option[idx].opcode)
	{
		if (!strcmp(inst, option[idx].opcode))
		{
			if (!strcmp(inst, "push"))
			{
				if (_isnum(elem))
				{
					s_elem = atoi(elem);
				}
				else
				{
					return (1);
				}
			}
			option[idx].f(stack, c);
			break;
		}
		idx++;
	}
	if (!option[idx].opcode)
	{
		return (-1);
	}
	return (0);
}
/**
 * main - Main funtion
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: Zero on success
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		token_it(argv[1]);
	} else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
