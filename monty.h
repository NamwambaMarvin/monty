#ifndef __MONTY
#define __MONTY
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#endif
#ifndef __PRTS
#define __PRTS
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct path_line - Contains the path and the line count
 * @path: File path
 * @line: Current line
 * Description: contains monty file path and line count
 */
typedef struct path_line
{
	FILE *path;
	char *line;
} file_line;
extern file_line fpath;
extern int s_elem;
void token_it(char *path);
int _isnum(char *c);
void free_list(stack_t *stack);
stack_t *new_node(int num);
void push_err(FILE *file, char *line, stack_t *stack, unsigned int count);
void option_err(FILE *file, char *line, stack_t *stack, char *count,
		unsigned int item);
int jump(stack_t **stack, char *inst, char *elem, size_t c);
void print_all(stack_t **stack, unsigned int n);
void pop_elem(stack_t **stack, unsigned int n);
void print_int(stack_t **stack, unsigned int n);
void clean(stack_t **stack);
void push_elem(stack_t **stack, unsigned int n);
void do_none(stack_t **stack, unsigned int n);
void add(stack_t **stack, unsigned int n);
void mul(stack_t **stack, unsigned int n);
void mod(stack_t **stack, unsigned int n);
void sub(stack_t **stack, unsigned int n);
file_line fpath;
void swap_elem(stack_t **stack, unsigned int n);
int s_elem;
#endif
