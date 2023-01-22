#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * mul - multiplies the first two elements
 * @stack: pointer to head
 * @line_number: line being executed
 *
 * The function stores the result in the second element
 * and the top element is removed
 * so the list is one element short
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = vars.top->next;
	ptr->n *= vars.top->n;
	pop(stack, line_number);
}

