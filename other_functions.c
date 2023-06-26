#include "monty.h"
/**
 * do_none - Prints all elements of the stack
 * @stack: Reference stack
 * @n: Line count
 */
void do_none(stack_t **stack, unsigned int n)
{
	(void)stack;
	(void)n;
}
/**
 * add - Adds elements of the stack
 * @stack: Reference stack
 * @n: Line Number
 */
void add(stack_t **stack, unsigned int n)
{
	int val = 0;
	stack_t *now = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	val = now->n + now->next->n;
	now->next->n = val;
	pop_elem(stack, n);
}

/**
 * sub - Subtracts elements of the stack
 * @stack: Reference stack
 * @n: Line Number
 */
void sub(stack_t **stack, unsigned int n)
{
	int sub = 0;
	stack_t *now = *stack;

	if (!now || !now->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	sub = now->next->n - now->n;
	now->next->n = sub;
	pop_elem(stack, n);
}
/**
 * mul - Multiplies elements of the stack
 * @stack: Reference stack
 * @n: Line Number
 */
void mul(stack_t **stack, unsigned int n)
{
	int val = 0;
	stack_t *now = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	now =  *stack;
	val = now->n * now->next->n;
	pop_elem(stack, n);
	now->next->n = val;
}
/**
 * mod - Modulates elements of the stack
 * @stack: Reference stack
 * @n: Line Number
 */
void mod(stack_t **stack, unsigned int n)
{
	int val = 0;
	stack_t *now = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	now = *stack;
	val = now->next->n % now->n;
	now->next->n = val;
	pop_elem(stack, n);
}
