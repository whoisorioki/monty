#include "monty.h"

/**
 * _arg - extracts an argument from a string
 * @str: string passed
 * Return: argument to opcode
 */
char *_arg(char *str)
{
	char *argument;
	int e = 0, r, i, s = 0;

	while (str[e] == ' ' || str[e] == '\t')
		e++;
	for (; str[e]; e++)
	{
		if (str[e] == '\n')
			return (NULL);
		else if (str[e] == ' ' || str[e] == '\t')
			break;
	}
	while (str[e] == ' ' || str[e] == '\t')
		e++;
	r = e;
	for (; str[e]; e++)
	{
		if (str[e] == '\n')
			break;
		s++;
	}
	if (s == 0)
		return (NULL);
	argument = _malloc((s + 1) * sizeof(char));
	for (i = 0; i < s; i++, r++)
		argument[i] = str[r];
	argument[i] = '\0';
	return (argument);
}

