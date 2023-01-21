#include "monty.h"
#include <stdlib.h>

/**
 * assign_fun - assigns function to monty
 * @check: int
 * @l_number: line being executed
 * Return: Nothing
 */
void assign_fun(int check, int l_number)
{
	switch (check)
	{
		case 0:
			vars.monty->f = push;
			break;
		case 1:
			vars.monty->f = pall;
			break;
		case 2:
			vars.monty->f = pint;
			break;
		case 3:
			vars.monty->f = pop;
			break;
		case 4:
			vars.monty->f = swap;
			break;
		case 5:
			vars.monty->f = add;
			break;
		case 6:
			vars.monty->f = nop;
			break;
		default:
			dprintf(2, "L%d: unknown instruction %s\n", l_number, vars.monty->opcode);
			free_all();
			exit(EXIT_FAILURE);

	}
}

/**
 * valid - checks if a command is valid
 * @line_number: line being executed
 * Return: int for position of command, -1 if command not found
 */
void valid(int line_number)
{
	char *command = vars.monty->opcode;
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
	assign_fun(check, line_number);
}

