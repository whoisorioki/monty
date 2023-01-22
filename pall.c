#include <stdio.h>
#include "monty.h"

/**
 * pall - prints all elements of a stack
 * @stack: pointer to header
 * @line_number: line
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	(void)stack;
	ptr = vars.top;
	while (ptr)
	{
		dprintf(1, "%d\n", ptr->n);
		ptr = ptr->next;
	}
}

