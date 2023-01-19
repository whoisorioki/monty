#include <stdlib.h>
#include "monty.h"

/**
 * free_all- free stack, buffer fro getline and monty
 * @buffer: pointer from getline
 * @monty: pinter to allocated memory space
 * At the end of the program, every list is freed
 * Return: Nothing
 */
void free_all(char *buffer, instruction_t *monty)
{
	stack_t *ptr;

	free(buffer);
	free(monty);
	if (top == NULL)
		return;
	while (top)
	{
		ptr = top;
		top = top->next;
		free(ptr);
	}
}

