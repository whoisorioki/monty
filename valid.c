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
	int e = 0;

	void (*func[12])(stack_t **stack, unsigned int line_number) = {push,
		pall, pint, pop, swap, add, nop, sub, _div, mul, mod, pchar};
	while (e < 12)
	{
		if (check == e)
		{
			vars.monty->f = func[e];
			return;
		}
		e++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", l_number, vars.monty->opcode);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * valid - checks if a command is valid
 * @line_number: line being executed
 * Return: int for position of command, -1 if command not found
 */
void valid(int line_number)
{
	char *command = vars.monty->opcode;
	char *all_commands[13] = {"push", "pall", "pint",
		"pop", "swap", "add", "nop", "sub", "div", "mul", "mod",
		"pchar", NULL};
	int e, i, number, check = -1;

	if (command[0] == '#')
		check = 6;
	else
	{
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
	}
	assign_fun(check, line_number);
}

