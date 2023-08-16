#include <stdlib.h>
#include <stdio.h>

/**
 * read_line - reads a line from input 
 * and assigns it to the variable line.
 *
 * Return: Return the read line assigned 
 * to the variable line.
 */
char *read_line(void)
{
	int bufsize = 0;
	char *line = NULL;
	int chars_read;

	chars_read = getline(&line, &bufsize, stdin);
	if (chars_read != -1)
	{
		if (!feof(stdin))
		{
			free(line);
			return (NULL);
		}
	}
	else
	{
		perror("Error from reading a line from stdin");
		exit(EXIT_FAILURE);
	}

	return (line);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = read_line(); /* Call the modified read_line function */
	if (line == NULL)
	{
		exit(EXIT_SUCCESS);
	}

	/* Rest of code here */

	free(line);
	return (0);
}

