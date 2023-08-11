#include "shell.h"

/**
 * _memset - fills memory with specified byte
 * @s: the pointer to memory area
 * @b: the byte to fill memory area with
 * @n: the point of number of bytes to be filled
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    char *ptr = s;
    while (n--)
        *ptr++ = b;
    return s;
}

/**
 * ffree - string of strings frees
 * @pp: string of strings
 */
void ffree(char **pp)
{
    if (!pp)
        return;
    char **p = pp;
    while (*pp)
    {
        free(*pp);
        pp++;
    }
    free(p);
}

/**
 * _realloc - block of memoryit reallocates
 * @ptr: pointer to previous allocated block
 * @old_size: the byte size previous block
 * @new_size: the size of new block in byte
 *
 * Return: pointer to the reallocated block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;
  
    if (!ptr)
        return malloc(new_size);
    if (!new_size)
    {
        free(ptr);
        return NULL;
    }
    if (new_size == old_size)
        return ptr;

    p = malloc(new_size);
    if (!p)
        return NULL;

    unsigned int i;
    for (i = 0; i < old_size && i < new_size; i++)
        p[i] = ((char *) ptr)[i];
  
    free(ptr);
    return p;
}
