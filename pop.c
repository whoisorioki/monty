#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pop - removes the top element of a stack
 * @stack: pointer to stack top layer
 * @line_number: line being executed
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if ((*stack) == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = vars.top;
	vars.top = vars.top->next;
	if (vars.top)
		vars.top->prev = NULL;
	*stack = vars.top;
	free(ptr);
}

