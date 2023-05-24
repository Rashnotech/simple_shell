#include "shell.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size:is the size of the allocated space for ptr
 * @new_size: the new size, of the new memory block
 * Return: pointer allocate new size memory, or NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr;
	unsigned int i, n = new_size;
	char *oldptr = ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		newptr = malloc(new_size);
		return (newptr);
	}

	else if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size > old_size)
		n = old_size;
	for (i = 0; i < n; i++)
		newptr[i] = oldptr[i];

	free(ptr);
	return (newptr);
}
