#include "main.h"

/**
 * interactive - receives commands and interpret them 
 *
 * Return: void
 */
void run_interactive_shell(void)
{
	char *line;
	char *args;
	int excute_shell;

	do
	{
		write(0, "$", 2);
		line = read_line();
		args = split_line(line);
		execute_status = execute_command(args, *name);

		free(line);
		free(args);

		if(execute_status >= 0)
		{
			exit(execute_status);
		}
		while(execute_status == -1)
	}
