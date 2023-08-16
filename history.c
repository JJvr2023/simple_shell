#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function stores the specified command in the history list. */
void add_to_history(char *command) {
  /* Declare a variable to store the history list. */
  static char *history[100];

  /* Get the current length of the history list. */
  int history_length = sizeof(history) / sizeof(history[0]);

  /* If the history list is full, remove the oldest command. */
  if (history_length == 100) {
    memmove(history, history + 1, (history_length - 1) * sizeof(history[0]));
  }

  /* Add the new command to the history list. */
  history[history_length - 1] = command;
}

/* This function prints the command history. */
void print_history() {
  /* Declare a variable to store the history list. */
  static char *history[100];

  /* Get the current length of the history list. */
  int history_length = sizeof(history) / sizeof(history[0]);

  /* If the history list is empty, print a message. */
  if (history_length == 0) {
    printf("The history list is empty.\n");
    return;
  }

  /* Print the history list. */
  for (int i = 0; i < history_length; i++) {
    printf("%d: %s\n", i + 1, history[i]);
  }
}

int main() {
  /* Declare a variable to store the command. */
  char command[256];

  /* Loop until the user enters the "exit" command. */
  while (1) {
    /* Prompt the user for a command. */
    printf("Command: ");

    /* Read the command from the standard input. */
    fgets(command, 256, stdin);

    /* Remove the newline character from the end of the command. */
    command[strcspn(command, "\n")] = '\0';

    /* If the command is "history", print the history list. */
    if (strcmp(command, "history") == 0) {
      print_history();
    } else {
      /* Add the command to the history list. */
      add_to_history(command);

      /* Execute the command. */
      system(command);
    }
  }

  return 0;
}
