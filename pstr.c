#include "monty.h"
#include <stdio.h>

/**
 * pstr - prints string from int
 * @stack: pointer to head
 * @line_number: line being executed
 *
 * function prints integers from top of stack as string
 * it terminates when stack is over, element is 0 or
 * when element is outside the range of ascii table
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)stack;
	(void)line_number;
	ptr = vars.top;
	while (ptr)
	{
		if (ptr->n <= 0 || ptr->n > 127)
			break;
		dprintf(1, "%c", ptr->n);
		ptr = ptr->next;
	}
	dprintf(1, "\n");
}

