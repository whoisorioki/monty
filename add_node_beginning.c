#include <stdlib.h>
#include "monty.h"

/**
 * add_node_beginning - adds node at the beginning of a list
 * @head: pointer to head pointer
 * @s: argument to be converted to int
 * @l_number: line number
 * Return: nothing
 */
void add_node_beginning(stack_t **head, char *s, int l_number)
{
	stack_t *ptr;
	int i;

	if (s == NULL)
	{
		dprintf(2, "L%d: usage: push integer\n", l_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(s);
	if (i == 0 && (s[0] != '0' || strlen(s) != 1))
	{
		dprintf(2, "L%d: usage: push integer\n", l_number);
		exit(EXIT_FAILURE);
	}
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ptr->n = i;
	ptr->prev = NULL;
	if (*head == NULL)
		ptr->next = NULL;
	else
		ptr->next = *head;
	*head = ptr;
}
