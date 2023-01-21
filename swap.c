#include "monty.h"
#include <stdlib.h>

/**
 * swap - swaps the value of of the first two elements of a stack
 * @stack: pointer to the stack_t struc
 * @line_number: line being executed
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	num = temp->n;
	temp->n = (*stack)->n;
	(*stack)->n = num;
}

