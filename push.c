#include "monty.h"
#include <stdlib.h>

/**
 * push - inserts data into a stack
 * @stack: pointer to header of my stack
 * @line_number: line of execution
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i;

	if (vars.arg == NULL)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	i = atoi(vars.arg);
	if (i == 0 && (vars.arg[0] != '0' || strlen(vars.arg) != 1))
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	new = _malloc(sizeof(stack_t));
	new->n = i;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}
