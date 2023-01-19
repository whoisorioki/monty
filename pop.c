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
	if (top == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->next;
	top->prev = NULL;
	free(*stack);
	*stack = top;
}

