#include "monty.h"
#include <stdlib.h>

/**
 * pint - prints the top element of a stack
 * @stack: pointer to a stack
 * @line_number: line being executed
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (top == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	dprintf(1, "%d\n", (*stack)->n);
}

