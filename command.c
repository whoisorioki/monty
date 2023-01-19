#include "monty.h"

/**
 * command - returns the command from the line read
 * @buffer: pointer to memory containing the line
 * Return: opcode
 */
char *command(char *buffer)
{
	size_t e, s, i;
	char *opcode;

	for (e = 0; buffer[e]; e++)
	{
		if (buffer[e] == '\n')
			return (NULL);
		else if (buffer[e] != ' ')
			break;
	}
	i = e;
	for (s = 0; buffer[e]; e++)
	{
		if (buffer[e] == ' ' || buffer[e] == '\n')
			break;
		++s;
	}
	opcode = _malloc((s + 1) * sizeof(char));
	for (e = 0; e < s; e++, i++)
		opcode[e] = buffer[i];
	opcode[e] = '\0';
	return (opcode);
}

