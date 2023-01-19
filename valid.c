#include "monty.h"
#include <stdlib.h>

/**
 * assign_fun - assigns function to monty
 * @monty: ponter
 * @check: int
 * @line_number: line being executed
 * Return: Nothing
 */
void assign_fun(instruction_t *monty, int check, int line_number)
{
	switch (check)
	{
		case 0:
			monty->f = push;
			break;
		case 1:
			monty->f = pall;
			break;
		case 2:
			monty->f = pint;
			break;
		case 3:
			monty->f = pop;
			break;
		case 4:
			monty->f = swap;
			break;
		case 5:
			monty->f = add;
			break;
		case 6:
			monty->f = nop;
			break;
		default:
			dprintf(2, "L%d: unknown instruction %s\n", line_number, monty->opcode);
			exit(EXIT_FAILURE);

	}
}

/**
 * valid - checks if a command is valid
 * @monty: header of monty stuct
 * @line_number: line being executed
 * Return: int for position of command, -1 if command not found
 */
int valid(instruction_t *monty, int line_number)
{
	char *command = monty->opcode;
	char *all_commands[8] = {"push", "pall", "pint",
		"pop", "swap", "add", "nop", NULL};
	int e, i, number, check = -1;

	for (e = 0, number = 0; all_commands[e]; number++, e++)
	{
		for (i = 0; command[i]; i++)
		{
			if (all_commands[e][i] != command[i])
				break;
		}
		if (command[i] == '\0' && all_commands[e][i] == '\0')
		{
			check = number;
			break;
		}
	}
	assign_fun(monty, check, line_number);
	return (check);
}

