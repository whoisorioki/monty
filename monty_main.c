#include <stdlib.h>
#include "monty.h"
globals_t vars;

/**
 * main - checks my code and runs opcodes
 * @ac: number of arguments
 * @av: pointer to arguments passed
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	size_t size = 0;
	int line_number = 1;
	stack_t *head = NULL;

	vars.buffer = NULL;
	vars.top =  NULL;
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	vars.stream = fopen(av[1], "r");
	if (vars.stream == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	vars.monty = _malloc(sizeof(instruction_t));
	while (getline(&vars.buffer, &size, vars.stream) != -1)
	{
		vars.monty->opcode = command(vars.buffer);
		if (vars.monty->opcode == NULL)
		{
			line_number++;
			continue;
		}
		valid(line_number);
		vars.arg = _arg(vars.buffer);
		vars.monty->f(&head, line_number);
		line_number++;
		if (vars.arg != NULL)
		{
			free(vars.arg);
			vars.arg = NULL;
		}
		free(vars.monty->opcode);
		vars.monty->opcode = NULL;
	}
	free_all();
	return (0);
}

