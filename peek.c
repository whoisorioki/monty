#include "monty.h"
#include <limits.h>

/**
 * peek - gets value of the top element in a stack
 * @top: pointer to the top of stack
 * Return: Nothing
 */
int peek(stack_t *top)
{
	if (top == NULL)
	{
		return (INT_MIN);
	}
	return (top->n);
}
