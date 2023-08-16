#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* This function prints the prompt and gets the user's command. */
char *get_command();

/* This function parses the specified command line into its arguments. */
char **parse_command(char *command);

/* This function executes the specified command. */
void execute_command(char **arguments);

#endif
