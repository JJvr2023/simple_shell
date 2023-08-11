#include <stdlib.h>

/**
 * bfree - frees a pointer and sets the pointer to NULL
 * @ptr: address of the pointer to free
 *
 * checks if a pointer is NULL Free the memory it point
 * and set the pointer to NULL
 * Return: 1 if freed.
 * 0 if pointer was NULL
 */
int bfree(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
