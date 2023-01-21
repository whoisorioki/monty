#include <stdlib.h>
#include "monty.h"

/**
 * free_all- free stack, buffer fro getline and monty
 * At the end of the program, every list is freed
 * Return: Nothing
 */
void free_all(void)
{
	stack_t *ptr;

	fclose(vars.stream);
	if (vars.buffer)
		free(vars.buffer);
	if (vars.monty->opcode)
		free(vars.monty->opcode);
	if (vars.monty)
		free(vars.monty);
	if (vars.arg)
		free(vars.arg);
	while (vars.head)
	{
		ptr = vars.head;
		vars.head = vars.head->next;
		free(ptr);
	}
}

