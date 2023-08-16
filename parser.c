#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* This function parses the specified command line into its arguments. */
char **parse_command(char *command) {
  /* Declare a variable to store the arguments. */
  char **arguments = malloc(10 * sizeof(char *));

  /* Declare a variable to track the current argument. */
  int current_argument = 0;

  /* Loop through the command line. */
  for (int i = 0; i < strlen(command); i++) {
    /* If the current character is a space, start a new argument. */
    if (command[i] == ' ') {
      /* Add the current argument to the list of arguments. */
      arguments[current_argument++] = malloc(i - current_argument + 1);
      strncpy(arguments[current_argument - 1], command + current_argument, i - current_argument);
      arguments[current_argument - 1][i - current_argument] = '\0';
      current_argument = i + 1;
    }
  }

  /* Add the last argument to the list of arguments. */
  arguments[current_argument++] = malloc(strlen(command) - current_argument + 1);
  strncpy(arguments[current_argument - 1], command + current_argument, strlen(command) - current_argument);
  arguments[current_argument - 1][strlen(command) - current_argument] = '\0';

  /* Return the list of arguments. */
  return arguments;
}

/* This function executes the specified command. */
void execute_command(char **arguments) {
  /* Fork a child process. */
  pid_t pid = fork();

  /* If the child process, execute the command. */
  if (pid == 0) {
    system(arguments[0]);
    exit(0);
  }

  /* If the parent process, wait for the child process to finish. */
  waitpid(pid, NULL, 0);
}

int main() {
  /* Get the command line from the user. */
  char *command = get_command();

  /* Parse the command line into arguments. */
  char **arguments = parse_command(command);

  /* Execute the command. */
  execute_command(arguments);

  /* Free the arguments. */
  for (int i = 0; i < current_argument; i++) {
    free(arguments[i]);
  }
  free(arguments);

  return 0;
}
