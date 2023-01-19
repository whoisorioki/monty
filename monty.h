#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack(or queue)
 * @n: integer
 * @prev: points to the previous element of stack(or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stacks, queues, LIFO, FIFO
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
void assign_fun(instruction_t *monty, int check, int line_number);
void *_malloc(size_t size);
char *command(char *buffer);
char *_arg(char *str);
int valid(instruction_t *monty, int line_number);
void add_node_beginning(stack_t **head, char *s, int l_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
extern stack_t *top;
void _free(char **, char **);
void free_all(char *, instruction_t *);

#endif
