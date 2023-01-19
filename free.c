#include <stdlib.h>

/**
 * _free - frees allocated memory and resets variables
 * @opcode: pointer to command
 * @arg: pointer to argument passed
 * Return: NOthing
 */
void _free(char **opcode, char **arg)
{
	free(*opcode);
	free(*arg);
	*opcode = NULL;
	*arg = NULL;
}

