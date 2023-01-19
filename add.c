#include "monty.h"
#include <stdlib.h>

/**
 * add - adds the first two elements of a stack
 * @stack: pointer to head
 * @line_number: line being executed
 *
 * Description - the sum is stored in the second element
 * The second element of stack then becomes the top
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (top->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = top->next;
	top->n = top->n + (*stack)->n;
	top->prev = NULL;
	free(*stack);
	(*stack) = top;
}

