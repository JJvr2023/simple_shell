#include <stdlib.h>
#include <stdio.h>

/**
 * read_line - reads line from input 
 * and assigns to variable line.
 *
 * Return: return strings and assigned 
 * to variable line.
 */
int main(void)
{
    int bufsize = 0;
    char *line = NULL;
    int chars_read;

    chars_read = getline(&line, &bufsize, stdin);
    if (chars_read != -1)
    {
        if (!feof(stdin))
        {
            exist(EXIST_SUCCESS);
            free(line);
            return 1;
        }
    }
    else
    {
        perror("Error from reading a line from stdin");
        exit(EXIT_FAILURE);
    }

    free(line);
    return 0;
}
