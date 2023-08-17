#include <stdio.h>
#include <unstd.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - where the execution of shell begin.
 * @argument count: shows number of command line arguments.
 * @argument vector: holds arguments.
 * Return: (0) Success
 */
int main(void)
{
	char *args;
	int *argc;

	int fd = STDIN_FILENO;

	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive(args[argc - 1]);
	}
	else
	{
		shell_non_interactive(args[argc - 1]);
	}
	return (0);
