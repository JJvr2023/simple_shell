#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

/*
 * This program implements a simple shell.
 */

int main(void) {
  /*
   * Set up a signal handler for the SIGINT signal.
   */
  signal(SIGINT, sigint_handler);

  /*
   * Infinite loop that prompts the user for a command and executes it.
   */
  while (1) {
    /*
     * Print the prompt.
     */
    printf("simple_shell_0.1$ ");

    /*
     * Read a line from the user.
     */
    char line[1024];
    fgets(line, sizeof(line), stdin);

    /*
     * Parse the line to get the command name and the arguments.
     */
    char *command = strtok(line, " ");
    char *arguments[10];
    int i = 0;
    while (arguments[i] = strtok(NULL, " "), arguments[i++] != NULL);

    /*
     * Execute the command.
     */
    execute_command(command, arguments);
  }

  return 0;
}

/*
 * This function handles the SIGINT signal.
 */
void sigint_handler(int signal) {
  /*
   * Print a message to the standard output.
   */
  printf("\n");
  printf("Received SIGINT signal.\n");

  /*
   * Exit the shell.
   */
  exit(0);
}

/*
 * This function executes the specified command.
 */
void execute_command(char *command, char *arguments[]) {
  /*
   * Check if the command is a built-in command.
   */
  if (strcmp(command, "echo") == 0) {
    echo_command(arguments);
  } else if (strcmp(command, "cd") == 0) {
    cd_command(arguments);
  } else if (strcmp(command, "pwd") == 0) {
    pwd_command();
  } else if (strcmp(command, "exit") == 0) {
    exit_command();
  } else {
    /*
     * The command is not implemented.
     */
    printf("Unknown command: %s\n", command);
  }
}

/*
 * This function prints the specified string to the standard output.
 */
void echo_command(char *arguments[]) {
  /*
   * Print each argument to the standard output.
   */
  for (int i = 0; arguments[i] != NULL; i++) {
    printf("%s ", arguments[i]);
  }

  /*
   * Print a new line.
   */
  printf("\n");
}

/*
 * This function changes the current working directory to the specified directory.
 */
void cd_command(char *arguments[]) {
  /*
   * If no argument is specified, change to the home directory.
   */
  if (arguments[1] == NULL) {
    chdir(getenv("HOME"));
  } else {
    /*
     * Change to the specified directory.
     */
    chdir(arguments[1]);
  }
}

/*
 * This function prints the current working directory to the standard output.
 */
void pwd_command() {
  /*
   * Get the current working directory.
   */
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));

  /*
   * Print the current working directory to the standard output.
   */
  printf("%s\n", cwd);
}

/*
 * This function exits the shell.
 */
void exit_command() {
  /*
   * Exit the shell.
   */
  exit(0);
}
