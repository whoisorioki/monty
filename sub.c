#include "monty.h"
#include "stdio.h"
#include <stdlib.h>

/**
 * sub - subtracts the top element from the second
 * @stack: pointer to head
 * @line_number: line being executed
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = vars.top->next;
	ptr->n -= vars.top->n;
	pop(stack, line_number);
}

