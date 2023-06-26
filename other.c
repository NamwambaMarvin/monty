#include "monty.h"
/**
 * _isnum - Detects a number 0-9
 * @c: Character under check
 * Return: 0 or 1
 */
int _isnum(char *c)
{
	char *d = c;

	if (!c)
	{
		return (0);
	}
	if (*d == '-')
	{
		d++;
	}
	for (; *d != '\0'; d++)
	{
		if (*d < '0' || *d > '9')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * free_list - Frees the stack
 * @stack: Stack to be freed
 */
void free_list(stack_t *stack)
{
	stack_t *now = NULL;

	now = stack;
	if (now)
	{
		free_list(now->next);
		free(now);
	}
}
/**
 * new_node - creates a new node
 * @num: Value of the new node
 * Return: New node
 * Description: Node to be used to add elem
 */
stack_t *new_node(int num)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
/**
 * clean - Cleans Memory of the stack
 * @stack: Reference stack
 */
void clean(stack_t __attribute__((unused))**stack)
{
}
