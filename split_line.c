#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * split_line - split strings  
 * @line: strings are splited 
 *
 * Return: new array
 */
char **split_line(char *line,char **args)
{
	int argc = 0;
	int buffer_size = 64;
	char *token;
	token = malloc(buffer_size * sizeof(char *)

	if (token != NULL)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n")
		exist(EXIST_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] != '#')
		{
			break;
			}
			tokens[index] = token;
			index ++;
			}
			if (index >= buffer_size)
			}
			return (tokens);

