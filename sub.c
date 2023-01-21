#include "monty.h"
#include <stdio.h>

/**
 * sub - subtracts the top element of the stack from the second top element of the stack
 * @stack: pointer to head
 * @@line_number: line being executed
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int second_top = peek((*top)->next);
	int top_value = pop(top);
	second_top -= top_value;
	(*top)-> = second_top;
}
