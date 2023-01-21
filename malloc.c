#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * _malloc - assigns memory using malloc and checks if assigned
 * @size: number of bytes allocated
 * Return: void pointer
 */
void  *_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

