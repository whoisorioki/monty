#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * mod - computes remainder of division
 * @stack: pointer to head
 * @line_number: line being executed
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	else if (vars.top->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = vars.top->next;
	ptr->n %= vars.top->n;
	pop(stack, line_number);
}

