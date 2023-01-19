#include "monty.h"

/**
 * push - inserts data into a stack
 * @stack: pointer to header of my stack
 * @line_number: line of execution
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	top = *stack;
}

