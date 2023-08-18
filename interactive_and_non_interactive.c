#include "main.h"

/**
 * interactive_mode - function for interactive mode
 * @name: program name
 *
 * Return: void
 */
void interactive_shell(void)
{
	while (1)
	{
		printf("$ ");
		char *line = read_line();
		if (!line)
		{
			fprintf(stderr, "Error reading input.\n");
			continue;
		}

		char **args = split_line(line);
		if (!args)
		{
			fprintf(stderr, "Error splitting strings.\n");
			free(line);
			continue;
		}

		int status = execute_args(args);

		free(args);
		free(line);

		if (status >= 0)
		{
			exit(status);
		}
		else
		{
			fprintf(stderr, "Error executing the command.\n");
		}
	}
}

/**
 * non_interactive_shell - function for non-interactive mode
 * @name: program name
 *
 * Return: void
 */
void non_interactive_shell(void)
{
	while (1)
	{
		char *line = read_stream();
		if (!line)
		{
			fprintf(stderr, "Error reading stream.\n");
			continue;
		}

		char **args = split_line(line);
		if (!args)
		{
			fprintf(stderr, "Error splitting lines.\n");
			free(line);
			continue;
		}

		int status = execute_args(args);

		free(args);
		free(line);

		if (status == 0)
		{
			exit(status);
		}

		while (status == -1)
		{
			/* handle error */
		}
	}
}

