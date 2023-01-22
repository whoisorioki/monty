#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pchar - prints the integer at the top as a char
 * @stack: pointer to head
 * @line_number: line being executed
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	else if (vars.top->n > 127 || vars.top->n < 0)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	dprintf(1, "%c\n", vars.top->n);
}

