#include <stdlib.h>
#include "monty.h"
stack_t *top = NULL;

/**
 * main - checks my code and runs opcodes
 * @ac: number of arguments
 * @av: pointer to arguments passed
 * Return: 0 if successful
 */
int main(int ac, char **av)
{
	FILE *stream;
	char *buffer = NULL, *arg;
	size_t size = 0;
	int code_number, line_number = 1;
	instruction_t *monty;
	stack_t *head;

	head =  NULL;
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(av[1], "r");
	if (stream == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	monty = _malloc(sizeof(instruction_t));
	while (getline(&buffer, &size, stream) != -1)
	{
		monty->opcode = command(buffer);
		if (monty->opcode == NULL)
			continue;
		code_number = valid(monty, line_number);
		arg = _arg(buffer);
		if (code_number == 0)
			add_node_beginning(&head, arg, line_number);
		monty->f(&head, line_number);
		line_number++;
		_free(&monty->opcode, &arg);
	}
	free_all(buffer, monty);
	fclose(stream);
	return (0);
}

