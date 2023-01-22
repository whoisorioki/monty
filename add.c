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
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	ptr = vars.top;
	vars.top = vars.top->next;
	vars.top->n = vars.top->n + ptr->n;
	vars.top->prev = NULL;
	*stack = vars.top;
	free(ptr);
}

