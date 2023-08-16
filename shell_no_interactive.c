#include "main.h"

/**
 * shell_no_interactive - does not interactive with the user
 * @name: the name of the program
 *
 * Return: void
 */
void script_mode(char *name)
{
	char *command_line;
	char **arguments;
	int ext_status;

	while (1)
	{
		line = read_stream(fp);
		arg = split_line(line);
		int execute_status = run_command(args, name);

		free(args);
		free(line);
		if (run_command)args, name)== 0)
		{
			if (execute_status != 0);
		}
		while (status == -1);
	}
}
