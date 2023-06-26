#include "monty.h"
/**
 * print_all - Prints all elements of the stack
 * @stack: Reference stack
 * @n: Line count
 */
void print_all(stack_t **stack, unsigned int n)
{
	stack_t *now = NULL;
	(void)n;
	now = *stack;

	if (now->next)
	{
		while (now)
		{
			dprintf(STDERR_FILENO, "%d\n", now->n);
			now = now->next;
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "%d\n", now->n);
	}
}
/**
 * push_elem - Prints all elements of the stack
 * @stack: Reference stack
 * @n: Line count
 */
void push_elem(stack_t **stack, unsigned int n)
{
	stack_t *new = NULL;
	(void)n;

	new = new_node(s_elem);
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * print_int - Prints all elements of the stack
 * @stack: Reference stack
 * @n: Line count
 */
void print_int(stack_t **stack, unsigned int n)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", n);
		clean(stack);
		exit(EXIT_FAILURE);
	} else
	{
		dprintf(STDERR_FILENO, "%d\n", (*stack)->n);
	}
}
/**
 * pop_elem - Prints all elements of the stack
 * @stack: Reference stack
 * @n: Line count
 */
void pop_elem(stack_t **stack, unsigned int n)
{
	stack_t *now = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", n);
		clean(stack);
		exit(EXIT_FAILURE);
	}
	now = *stack;
	*stack = now->next;
	if (now->next != NULL)
		now->next->prev = now->prev;
	free(now);
}
/**
 * swap_elem - Prints all elements of the stack
 * @stack: Reference stack
 * @n: Line count
 */
void swap_elem(stack_t **stack, unsigned int n)
{
	stack_t *current = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		clean(stack);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
