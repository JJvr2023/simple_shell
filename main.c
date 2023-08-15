#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* This function prints the prompt and gets the user's command. */
char *get_command() {
  /* Print the prompt. */
  printf("simple_shell>");

  /* Get the user's command. */
  char *command = malloc(1024 * sizeof(char));
  fgets(command, 1024, stdin);

  /* Remove the newline character from the end of the command. */
  command[strcspn(command, "\n")] = '\0';

  return command;
}

/* This function executes the specified command. */
void execute_command(char *command) {
  /* Fork a child process. */
  pid_t pid = fork();

  /* If the child process, execute the command. */
  if (pid == 0) {
    system(command);
    exit(0);
  }

  /* If the parent process, wait for the child process to finish. */
  waitpid(pid, NULL, 0);
}

int main() {
  /* Loop until the user enters the "exit" command. */
  while (1) {
    /* Get the user's command. */
    char *command = get_command();

    /* If the command is "exit", exit the shell. */
    if (strcmp(command, "exit") == 0) {
      break;
    }

    /* Execute the command. */
    execute_command(command);
  }

  return 0;
}
